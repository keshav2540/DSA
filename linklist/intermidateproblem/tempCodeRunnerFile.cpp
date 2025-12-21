
         return 1;
     }else return 0;
 }
 node*add1recursively(node*head){
    int carry=helper(head);
    if(carry==1){