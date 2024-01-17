

class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
 
class MergeKSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        ListNode head=new ListNode(Integer.MIN_VALUE);
        // int j=1;
        for(int i=0;i<lists.length;i++){
            head=mergeList(head,lists[i]);
            // if(j==1) return head;
            // j+=1;
        }
        return (head!=null)?head.next:head;
    }
    public ListNode mergeList(ListNode head,ListNode to){
        if(to==null) return head;
        int size=0;
        ListNode temp=to;
        while(temp!=null){
            size+=1;
            temp=temp.next;
        }
        // System.out.println(size);
        ListNode temp1=head;
        // int j=1;
        for(int i=0;i<size;i++){
            temp1=head;
            ListNode toattach=to;
            to=to.next;
            while((temp1.next!=null && temp1.next.next!=null) && ((temp1.val==temp1.next.val) || (temp1.val<toattach.val && temp1.next.val<toattach.val && temp1.val<toattach.val) )){
                temp1=temp1.next;
            }
            // if(temp1!=null) System.out.println(temp1.val+"ppp");
            if(temp1.next!=null && temp1.val<toattach.val && temp1.next.val<toattach.val) temp1=temp1.next;
            // System.out.println(temp1.val+" ");
            toattach.next=temp1.next;
            temp1.next=toattach;
            // if(j==1) return head;
            // j+=1;
        }
        return head;
    }
}
