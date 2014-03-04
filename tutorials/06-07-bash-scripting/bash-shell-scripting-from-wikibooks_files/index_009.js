// This page is for keeping track of JavaScript that may no longer be useful/functional someday.

var addLoadEvent = addOnloadHook;
var import_script = importScript;
var import_style = importStylesheet;
 
function get_query_value(query, name)
{
	var value = (name && query && query.match && query.match('[&?]' + name + '=([^&]*)') || '');
	return value && decodeURIComponent(value[1]) || '';
}

// Removes the default no-license option for uploads.
function remove_no_license()
{
	if ( mw.config.get('wgCanonicalSpecialPageName') !== 'Upload' )
		return;
	$('#wpLicense').find('option').eq(0).remove();
}

$(document).ready(remove_no_license);