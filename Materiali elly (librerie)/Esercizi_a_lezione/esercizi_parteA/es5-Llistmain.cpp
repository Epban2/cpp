  void traverse_rec(Link<E>* elem)
  {
      if (elem->next == NULL) return; //allora è l'ultimo elemento
      visit(elem->next);
      traverse_rec(elem->next);
  }