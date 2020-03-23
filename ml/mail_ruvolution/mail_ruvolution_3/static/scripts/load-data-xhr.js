window.onload = function() {
    setInterval(function() {
        var xhr = new XMLHttpRequest();
        xhr.open("POST", "/load_status", true);

        if (xhr.status != 200) {
            console.log( xhr.status + ': ' + xhr.statusText );
        } else {
            console.log( JSON.stringify(xhr.responseText) );
        }
    }, 2000);
};
