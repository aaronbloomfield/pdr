class huffman_node {
    int frequency;
    unsigned char c;
    huffman_node* left, *right;
};


void create_path (huffman_node* node, char leaf, string prefix_code) {

    // how recursion stops
    if ( prefix_code == "" ) {
        node->c = leaf;
        return;
    }

    // make the problem simpler (i.e., the actual recursion)
    if ( prefix_code[0] == '0' ) {
        // go to the left
        ensure_there_is_a_left_child_of_node();
        create_path (node->left, leaf, prefix_code_minus_first_character);
    } else { // first character is a '1'
        // go to the right
        ensure_there_is_a_right_child_of_node();
        create_path (node->right, leaf, prefix_code_minus_first_character);
    }
}

int main() {
    huffman_node* root = create_new_node();
    for ( each character / prefix_code pair )
        create_path (root, character, prefix_code);
