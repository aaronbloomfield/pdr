


void create_path (HuffmanNode* node, char leaf, string prefix_code) {

    // how recursion stops
    if ( prefix_code == "" ) {
        node->character = leaf;
        return;
    }

    // make problem simpler (i.e., the actual recursion)
    first_char = first_character_of_prefix_code();
    if ( first_char == '0' ) {
        ensure_there_is_a_left_child_of_node();
        create_path (node->left, leaf, prefix_code_minus_first_character);
    } else { // first_char is a '1'
        ensure_there_is_a_right_child_of_node();
        create_path (node->right, leaf, prefix_code_minus_first_character);
    }

}



int main() {

    root = create_new_node();
    for ( each character - prefix_code pair )
        create_path (root, character, prefix_code);

}



/*

binary_heap::print() for the tree on slide 5.9:

         10
    20        80
 40     60   99 85
50 700

*/
