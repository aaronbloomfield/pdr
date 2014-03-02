function add_toolbox_link(action, name, id)
{
	var $tools = $('#p-tb ul');
	if ( !$tools.length ) return;
	if (typeof action == "string") {
		$tools.append('<li id="t-' + (id || name) + '"><a href="' + action + '">' + name + '</a></li>');
	} else if (typeof action == "function") {
		$('<li id="t-' + (id || name) + '"><a>' + name + '</a></li>').appendTo($tools).click(action);
	}
}

function add_all_user_tools()
{
	if (wgNamespaceNumber != 2 && wgNamespaceNumber != 3) return;

	var username = encodeURIComponent(wgTitle.split("/", 1)[0]);
	var project = wgServer.replace("http://", "");
	var filebase = 'http://tools.wikimedia.de/~daniel/WikiSense/UntaggedImages.php?';
	var delimg = 'Files_with_unknown_copyright_status';

	add_toolbox_link(filebase + 'wiki=' + project + '&img_user_text=' + username , 'untagged', 'untagged');
}

if (typeof gadget_removeimagetools == 'undefined')
	var gadget_removeimagetools = 0;
if (gadget_removeimagetools != 1)
	$(document).ready(add_all_user_tools);