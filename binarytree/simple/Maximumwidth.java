 class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{
    public int height(Node root){
        if(root==null) return 0;
        int height1=height(root.left);
        int height2=height(root.right);
        return 1+Math.max(height1,height2);} 
    }
public class  Maximumwidth{
    public static void main(){
            Node root=new Node(1);
             root.left=new Node(2);
             root.right=new Node(2);
             Solution s=new Solution();
             System.out.println(s.height(root));
      } 
}   
