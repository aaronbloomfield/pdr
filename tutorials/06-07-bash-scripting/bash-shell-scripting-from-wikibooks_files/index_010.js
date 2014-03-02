// Move icons and navigation to top of content area, which should place them right below the page title

$(document).ready( function() {
	var $where = mw.util.$content, $what = $where.find('.topicon').css('display', 'inline');
	
	if ( $what.length ) {
		$where.find('h1,h2,h3,h4,h5,h6').eq(0)
			.wrapInner('<span />').append( $('<span id="page-status" />').append($what) );
	}
	
	$where = $where.find('#mw-content-text');
	
	$what = $where.find('#bottom-navigation').remove().slice(0,1);
	while ( $where.find('#bottom-navigation').remove().length );
	if ( $what.length ) { $where.after($what); }
	
	$what = $where.find('#top-navigation').remove().slice(0,1);
	while ( $where.find('#top-navigation').remove().length );
	$where = $where.parent().find('.subpages').add($where).slice(0,1);
	if ( $what.length ) { $where.before($what); }
});