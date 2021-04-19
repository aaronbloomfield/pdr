

class huffman_node {
    int frequency;
    unsigned char c;
    huffman_node* left, *right;
};



void count_freqs () {

    int freq[256];
    for ( i = 0 -> 255 )
        freq[i] = 0;

    while ( file_still_has_stuff_for_us_to_read() ) {
        unsigned char c = get_next_character();
        cout << (int) c << endl;
        if ( (c < 0x20) || (c > 0x7e) )
            continue;
        if ( (c < 32) || (c > 126) )
            continue;
        if ( (c < ' ') || (c > '~') )
            continue;
        freq[c]++;
    }
}


void determine_prefix_codes (huffman_node* node, string path_taken) {

    if ( node_has_no_children() ) {
        // recursion ends
        cout << node->c << ": " << path_taken << endl;

    } else { // node must have 2 children
        // recursion continues
        determine_prefix_nodes (node->right, path_taken + "1");
        determine_prefix_nodes (node->left,  path_taken + "0");


    }

}

determine_prefix_nodes (root, "");
