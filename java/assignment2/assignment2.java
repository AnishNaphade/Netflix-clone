public class assignment2 {


public static void main(String[] args) {

int []arr = new int[5];
arr[0]=2;
arr[1]=3;
arr[2]=4;
arr[3]=5;
arr[4]=6;
int targSum = 9;
for(int i=0;i<=4;i++){
for(int k=1;k<=4;k++){

if(arr[i]+arr[k]==targSum){
System.out.print(i);
System.out.println(k);}
    }
                     }

}

}