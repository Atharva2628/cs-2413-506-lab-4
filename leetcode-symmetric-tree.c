bool mirrored_checking(struct TreeNode* a, struct TreeNode* b) {
  //when both = null, that means they are symmetric so true
  if (a == NULL && b == NULL) {
    return true;
  }

  //else not symmetric so false
  if (a == NULL || b == NULL) {
    return false;
  }
  //do the actual match and see if subtrees are mirrored to each other
  return (a->val == b->val) &&
         mirrored_checking(a->left, b->right) &&
         mirrored_checking(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
  return mirrored_checking(root->left, root->right);
}