$(function() {

		function onResize() {
			conferenceItemsEqHght();
			advItemsEqHght();
			alignVertTraining();
			alignVertGuarantee();
			priceListItemsEqHght();
	  }onResize();
	  window.onresize = function() {onResize()};

	$(".toggle-mnu").click(function() {
	  $(this).toggleClass("on");
	  $(".top-line").toggleClass('open');
	  $(".main-menu").slideToggle(700);
	  return false;
	});

	$('.main-menu .menu li a').on('click', function (event) {
    event.preventDefault();
    var id  = $(this).attr('href'),
    top = $(id).offset().top;
    $('body,html').animate({scrollTop: top}, 1000);
    if($(window).width() < 992) {
	    $(".top-line").toggleClass('open');
		  $(".main-menu").slideToggle(400);
		  $(".toggle-mnu").toggleClass("on");
    }
  });

  $('.nav-scroll').on('click', function (event) {
    event.preventDefault();
    var id  = $(this).attr('href'),
    top = $(id).offset().top;
    $('body,html').animate({scrollTop: top}, 1000);
  });

  function conferenceItemsEqHght() {
    var max_col_height = 0;
    var a = $('.conference-item');
    a.css('height', '')
    a.each(function(){
      if ($(this).height() > max_col_height) {
        max_col_height = $(this).height();
      }
    });
    a.height(max_col_height);
  }conferenceItemsEqHght();

  function advItemsEqHght() {
    var max_col_height = 0;
    var a = $('.you-will-get-item');
    a.css('height', '')
    a.each(function(){
      if ($(this).height() > max_col_height) {
        max_col_height = $(this).height();
      }
    });
    a.height(max_col_height);
  }advItemsEqHght();

  $('.open-conference .button').on('click', function(e) {
  	e.preventDefault();
  	$(this).fadeToggle();
  	$('.conference-wrapper').fadeIn();
  	conferenceItemsEqHght();
  });

  function alignVertTraining() {
		$('.training-map-item--step').each(function() {
	  	var a = $(this).find('.questions-block'),
	  			b = $(this).find('.questions-list');
	  	b.css('margin-top', (a.outerHeight() - b.outerHeight()) / 2 + 'px');
	  });
  }alignVertTraining();

  $('.open-training-map .button').on('click', function(e) {
  	e.preventDefault();
  	$(this).css('display', 'none');
  	$('.training-map-wrapper').fadeIn();
  	alignVertTraining();
  });

  $('.people-end-training-wrapper .full-list .button').on('click', function(e) {
  	e.preventDefault();
  	$(this).css('display', 'none');
  	$(".people-end-training-wrapper [class*='col-lg']").css('display', 'block');
  });

  $('.testimonials-carousel').owlCarousel({
  	margin : 30,
		loop : true,
		nav : true,
		dots : true,
		navText: ['<img src="img/slider-nav/arrow-left.png" alt="" />', '<img src="img/slider-nav/arrow-right.png" alt="" />'],
    responsive:{
  		320:{
        items:1
      },
      480:{
          items:1
      },
      768:{
          items:2
      },
      992:{
          items:3,
          margin : 30
      },
      1200:{
      	items:3,
      	margin: 70
      }
    }
  });

  function alignVertGuarantee() {
		$('.guarantee-item').each(function() {
	  	var a = $(this).find('.guarantee-item-title'),
	  			b = $(this).find('.guarantee-item-content');
	  	b.css('margin-top', (a.outerHeight() - b.outerHeight()) / 2 + 'px');
	  });
  }alignVertGuarantee();

  function priceListItemsEqHght() {
    var max_col_height = 0;
    var a = $('.price-list-item .price-list-item--body');
    a.css('height', '')
    a.each(function(){
      if ($(this).height() > max_col_height) {
        max_col_height = $(this).height();
      }
    });
    a.height(max_col_height);
  }priceListItemsEqHght();

  $('.answer-on-questions-item .title').on('click', function() {
  	$(this).parent().toggleClass('open');
  	$(this).parent().find('.content').toggle();
  });

});
