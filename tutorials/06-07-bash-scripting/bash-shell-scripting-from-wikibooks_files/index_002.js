/**
 * Hide prefix in category
 *
 * @source: http://www.mediawiki.org/wiki/Snippets/Hide_prefix_in_category
 * @rev: 2
 * @author: Krinkle
 */

$(document).ready( function() {
  var prefix = $( '#mw-cat-hideprefix' ).text();
  if ( $.trim( prefix ) === '' ) {
    prefix = mw.config.get( 'wgTitle' ) + '/';
  }
  $( '#mw-pages' ).add( '#mw-subcategories' ).find( 'a' ).text( function( i, val ) {
    return val.replace( new RegExp( '^' + $.escapeRE( prefix ) ), '' );
  });
});