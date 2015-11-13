// Full list of configuration options available here:
// https://github.com/hakimel/reveal.js#configuration
Reveal.initialize({
    controls: true,
    progress: true,
    history: true,
    center: true,
    slideNumber: true,
    transition: 'slide', // none/fade/slide/convex/concave/zoom
    math: {
        mathjax: 'https://cdn.mathjax.org/mathjax/latest/MathJax.js',
        config: 'TeX-AMS_HTML-full'  // See http://docs.mathjax.org/en/latest/config-files.html
    },
    // Optional reveal.js plugins
    dependencies: [
        { src: 'reveal.js/plugin/math/math.js', async: true },
	{ src: 'reveal.js/lib/js/classList.js', condition: function() { return !document.body.classList; } },
	{ src: 'reveal.js/plugin/markdown/marked.js', condition: function() { return !!document.querySelector( '[data-markdown]' ); } },
	{ src: 'reveal.js/plugin/markdown/markdown.js', condition: function() { return !!document.querySelector( '[data-markdown]' ); } },
	//{ src: 'reveal.js/plugin/highlight/highlight.js', async: true, condition: function() { return !!document.querySelector( 'pre code' ); }, callback: function() { hljs.initHighlightingOnLoad(); } },
        { src: 'plugin/highlight/highlight.js', async: true, callback: function() { hljs.initHighlightingOnLoad(); } },
	{ src: 'reveal.js/plugin/zoom-js/zoom.js', async: true },
	{ src: 'reveal.js/plugin/notes/notes.js', async: true }
    ]
});
