package Assignment5;

import java.util.*;

class Order {
    int oid;
    List<String> itemName;
    boolean cash;

    Order(int oid, List<String> itemName, boolean cash) {
        this.oid = oid;
        this.itemName = itemName;
        this.cash = cash;
    }
}

public class a5 {
    

    public List<String> getItems(List<Order> orders) { 
        List<String> items = new ArrayList<String>();
        for (Order o : orders) {
            items.addAll(o.itemName); 
        }
        return items;
    }

    public static void main(String[] args) {
        List<String> items1 = new ArrayList<String>();
        items1.add("Jeans");
        items1.add("Shirt");

        List<String> items2 = new ArrayList<String>();
        items2.add("Shoes");
        items2.add("T-shirt");

        List<String> items3 = new ArrayList<String>();
        items3.add("Shirt");
        items3.add("Shoes");

        List<Order> orderList = new ArrayList<Order>(); 
        orderList.add(new Order(1, items1, true));
        orderList.add(new Order(2, items2, false));
        orderList.add(new Order(3, items3, true));

        a5 mapExample = new a5(); 
        List<String> items = mapExample.getItems(orderList); 
        System.out.println(items);
    }
}