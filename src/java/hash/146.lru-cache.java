/*
 * @lc app=leetcode id=146 lang=java
 *
 * [146] LRU Cache
 */

// @lc code=start
import java.util.*;

class LRUCache {

   private Map<Integer,Integer> map = new HashMap<>();
    private LinkedList<Integer> list = new LinkedList<>();
    private int capacity ;
    
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
   
        Integer existingValue = map.get(key);

       
        if(existingValue !=null) {
            //we will update the list
            list.remove((Integer)key);
            list.addFirst(key);
        } else{
            existingValue = -1;
        }
     

        return existingValue;
        
        
    }
    
    public void put(int key, int value) {
    
        Integer existingValue = map.get(key);
        int currentCapacity  = map.size();

        if(existingValue != null) { // the key could already exist
             list.remove((Integer)key);
        } else  if(currentCapacity>= capacity) {
            //remove last element to make way for the new one
             int key1 = list.removeLast();
            map.remove(key1);
        
        }
          
        list.addFirst(key);
        map.put(key, value);     


       
    }
}

    
    


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

