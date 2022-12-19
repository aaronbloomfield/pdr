// Full list of configuration options available here:
// https://github.com/hakimel/reveal.js#configuration

Reveal.initialize({

    // Display presentation control arrows
    controls: true,

    // Help the user learn the controls by providing hints, for example by
    // bouncing the down arrow when they first encounter a vertical slide
    //controlsTutorial: true,
    controlsTutorial: false,

    // Determines where controls appear, "edges" or "bottom-right"
    controlsLayout: 'bottom-right',

    // Visibility rule for backwards navigation arrows; "faded", "hidden"
    // or "visible"
    controlsBackArrows: 'faded',

    // Display a presentation progress bar
    progress: true,

    // Display the page number of the current slide
    //slideNumber: false,
    slideNumber: true,

    // Push each slide change to the browser history
    //history: false,
    history: true,
    
    // Enable keyboard shortcuts for navigation
    keyboard: true,

    // Enable the slide overview mode
    overview: true,

    // Vertical centering of slides
    //center: true,
    center: false,

    // Enables touch navigation on devices with touch input
    touch: true,

    // Loop the presentation
    loop: false,

    // Change the presentation direction to be RTL
    rtl: false,

    // Randomizes the order of slides each time the presentation loads
    shuffle: false,

    // Turns fragments on and off globally
    fragments: true,

    // Flags whether to include the current fragment in the URL,
    // so that reloading brings you to the same fragment position
    fragmentInURL: false,

    // Flags if the presentation is running in an embedded mode,
    // i.e. contained within a limited portion of the screen
    embedded: false,

    // Flags if we should show a help overlay when the questionmark
    // key is pressed
    help: true,

    // Flags if speaker notes should be visible to all viewers
    showNotes: false,

    // Global override for autoplaying embedded media (video/audio/iframe)
    // - null: Media will only autoplay if data-autoplay is present
    // - true: All media will autoplay, regardless of individual setting
    // - false: No media will autoplay, regardless of individual setting
    autoPlayMedia: null,

    // Number of milliseconds between automatically proceeding to the
    // next slide, disabled when set to 0, this value can be overwritten
    // by using a data-autoslide attribute on your slides
    autoSlide: 0,

    // Stop auto-sliding after user input
    autoSlideStoppable: true,

    // Use this method for navigation when auto-sliding
    autoSlideMethod: Reveal.navigateNext,

    // Specify the average time in seconds that you think you will spend
    // presenting each slide. This is used to show a pacing timer in the
    // speaker view
    defaultTiming: 120,

    // Enable slide navigation via mouse wheel
    mouseWheel: false,

    // Hides the address bar on mobile devices
    hideAddressBar: true,

    // Opens links in an iframe preview overlay
    // Add `data-preview-link` and `data-preview-link="false"` to customise each link
    // individually
    previewLinks: false,

    // Transition style
    transition: 'slide', // none/fade/slide/convex/concave/zoom

    // Transition speed
    transitionSpeed: 'default', // default/fast/slow

    // Transition style for full page slide backgrounds
    backgroundTransition: 'fade', // none/fade/slide/convex/concave/zoom

    // Number of slides away from the current that are visible
    viewDistance: 3,

    // Parallax background image
    parallaxBackgroundImage: '', // e.g. "'https://s3.amazonaws.com/hakim-static/reveal-js/reveal-parallax-1.jpg'"

    // Parallax background size
    parallaxBackgroundSize: '', // CSS syntax, e.g. "2100px 900px"

    // Number of pixels to move the parallax background per slide
    // - Calculated automatically unless specified
    // - Set to 0 to disable movement along an axis
    parallaxBackgroundHorizontal: null,
    parallaxBackgroundVertical: null,

    // The display mode that will be used to show slides
    display: 'block',

    // ????
    hash: true,

    math: {
      mathjax: 'https://cdn.jsdelivr.net/gh/mathjax/mathjax@2.7.8/MathJax.js',
      config: 'TeX-AMS_HTML-full',
      // pass other options into `MathJax.Hub.Config()`
      TeX: { Macros: { RR: "{\\bf R}" } }
    },

    // Learn about plugins: https://revealjs.com/plugins/
    plugins: [ RevealZoom, RevealNotes, RevealSearch, RevealMarkdown, RevealHighlight, RevealMath ],

});

/*
Reveal.initialize({

    math: {
	mathjax: 'https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js',
	config: 'TeX-AMS_HTML-full'  // See http://docs.mathjax.org/en/latest/config-files.html
    },
    
    dependencies: [
	// Cross-browser shim that fully implements classList - https://github.com/eligrey/classList.js/
	{ src: 'reveal.js/lib/js/classList.js', condition: function() { return !document.body.classList; } },

	// Interpret Markdown in <section> elements
	{ src: 'reveal.js/plugin/markdown/marked.js', condition: function() { return !!document.querySelector( '[data-markdown]' ); } },
	{ src: 'reveal.js/plugin/markdown/markdown.js', condition: function() { return !!document.querySelector( '[data-markdown]' ); } },

	// Syntax highlight for <code> elements
	{ src: 'reveal.js/plugin/highlight/highlight.js', async: true, callback: function() { hljs.initHighlightingOnLoad(); } },

	// Zoom in and out with Alt+click
	{ src: 'reveal.js/plugin/zoom-js/zoom.js', async: true },

	// Speaker notes
	{ src: 'reveal.js/plugin/notes/notes.js', async: true },

	// MathJax
	{ src: 'reveal.js/plugin/math/math.js', async: true }
    ],

});
*/
