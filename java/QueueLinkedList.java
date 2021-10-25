/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queuelinkedlist;

/**
 *
 * @author lenovo
 */
public class QueueLinkedList {

   public static class Queue{
       Node front,rear;
      public static class Node{
          int data;
          Node next;
      }
      void enqueu(int data){
          Node jet=new Node();
              if(front==null){
                  jet.data=data;
                 front=rear=jet;
                  System.out.println("Added To Queue");
      }
              else{
                  rear.next=jet;
                  jet.data=data;
                  rear=jet;
                  System.out.println("Added To Queue");
      }
      }
      void deletequeue(){
          if (front == null) 
			return; 

		Node jet = front; 
                System.out.println("Value "+front.data+"has been deleted from the queue");
		front = front.next; 
                
		if (front == null) 
			rear = null;  
      }
      
   }
    public static void main(String[] args) {
       Queue first=new Queue();
       first.enqueu(1);
       first.enqueu(2);
       first.enqueu(3);
       first.enqueu(4);
        System.out.println("Front:"+first.front.data);
        first.deletequeue();
        System.out.println("New Front:"+first.front.data);
    }
    
}
