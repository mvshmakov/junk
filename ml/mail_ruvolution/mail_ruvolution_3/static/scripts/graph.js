//document.addEventListener("DOMContentLoaded", cb)
window.onload = function() {
    var documentHeight = window.innerHeight,
        documentWidth = window.innerWidth;

    var width = documentWidth,
        height = documentHeight,
        root;

    var force = d3.layout.force()
        .linkDistance(function(d) { return randomInteger(100, 250)})
        .charge(-120)
        .gravity(-0.05)
        .size([width, height])
        .on("tick", tick);

    var svg = d3.select("main").append("svg")
        .attr("width", width)
        .attr("height", height);

    var link = svg.selectAll(".link"),
        node = svg.selectAll(".node");

    d3.json("../static/data/main-graph.json", function(error, json) {
      if (error) throw error;

      root = json;
      update();
    });

    function randomizeIndeces(id) {
        return Math.random() * id;
    };

    function randomInteger(min, max) {
        var rand = min - 0.5 + Math.random() * (max - min + 1)
        rand = Math.round(rand);
        return rand;
    };

    function update() {
      var nodes = flatten(root),
          links = d3.layout.tree().links(nodes);

      nodes[nodes.length-1].x = width / 2;
      nodes[nodes.length-1].y = height / 2;
      nodes[nodes.length-1].fixed = true;

      // Restart the force layout.
      force
          .nodes(nodes)
          .links(links)
          .start();

      // Update links.
      link = link.data(links, function(d) { return randomizeIndeces(d.target.id); });

      link.exit().remove();

      link.enter().insert("line", ".node")
          .attr("class", "link");

      // Update nodes.
      node = node.data(nodes, function(d) { return randomizeIndeces(d.id); });

      node.exit().remove();

      var nodeEnter = node.enter().append("g")
          .attr("class", "node")
          .on("click", click)
          .call(force.drag);

      nodeEnter.append("circle")
          .attr("r", function(d) { return Math.sqrt(d.size * 30) / 10 || 4.5 * 9; });

      nodeEnter.append("text")
          .attr("dy", ".35em")
          .text(function(d) { return d.name; });

      node.select("circle")
          .style("fill", color);
    }

    function tick() {
      link.attr("x1", function(d) { return d.source.x; })
          .attr("y1", function(d) { return d.source.y; })
          .attr("x2", function(d) { return d.target.x; })
          .attr("y2", function(d) { return d.target.y; });

      node.attr("transform", function(d) { return "translate(" + d.x + "," + d.y + ")"; });
    }

    function color(d) {
      return d._children ? "#3182bd" // collapsed package
          : d.children ? "#c6dbef" // expanded package
          : "#fd8d3c"; // leaf node
    }

    // Toggle children on click.
    function click(d) {
      if (d3.event.defaultPrevented) return; // ignore drag

      if (document.getElementById("mySidenav").style.width != "0") {
          closeNav();
      };
      if (document.getElementById("responseSideNav").style.width != "0") {
          closeResponseSideNav();
      };

      if (d.type == "Root" && d.children) {
          return update();
      }
      else if (d.type == "Category" && !d.children) {
          var xhr = new XMLHttpRequest();
          xhr.open("POST", "/get_class_children", false);
          xhr.setRequestHeader('Content-Type', 'application/json');
          xhr.send(JSON.stringify({ "name": d.name }));

          if (xhr.status != 200) {
              console.log( xhr.status + ': ' + xhr.statusText );
          } else {
              root = JSON.parse(xhr.responseText);
          }
      }
      else if (d.type == "Category" && d.children) {
          var xhr = new XMLHttpRequest();
          xhr.open("POST", "/get_target_children", false);
          xhr.setRequestHeader('Content-Type', 'application/json');
          console.log(d.email)

          obj_params = {
              email: d.email
          }

          xhr.send(JSON.stringify(obj_params));

          if (xhr.status != 200) {
              console.log( xhr.status + ': ' + xhr.statusText );
          } else {
              root = JSON.parse(xhr.responseText);
          }
      }
      else if (d.type == "Mail") {
          var xhr = new XMLHttpRequest();
          xhr.open("POST", "/get_mail", false);
          xhr.setRequestHeader('Content-Type', 'application/json');
          xhr.send(JSON.stringify({ "name": d.target }));

          if (xhr.status != 200) {
              console.log( xhr.status + ': ' + xhr.statusText );
          } else {
              message_data = JSON.parse(xhr.responseText);

              document.getElementById("subject").innerHTML = "Тема: " + message_data["subject"];
              document.getElementById("text").innerHTML = message_data["text"];
              document.getElementById("date").innerHTML = message_data["date"];
              document.getElementById("target").innerHTML = message_data["target"];

              spamIndex(message_data["text"], message_data["target"]).then(function(resp) {
                            document.getElementById("spam-index").innerHTML = resp;
              })

              // document.getElementById("subject").innerHTML = message_data["subject"];
              // document.getElementById("text").innerHTML = message_data["text"];
              // document.getElementById("target").innerHTML = message_data["target"];
              // document.getElementById("targetDate").innerHTML = (new Date()).getTime();

              openNav();
          }
      }
      update();
    }

    // Returns a list of all nodes under the root.
    function flatten(root) {
      var nodes = [], i = 0;

      function recurse(node) {
        if (node.children) node.children.forEach(recurse);
        if (!node.id) node.id = ++i;
        nodes.push(node);
      }

      recurse(root);
      return nodes;
    }
};
