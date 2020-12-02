package bubbleSort;
import java.util.*;

public class BubbleSort {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of elements you want to sort: ");
		int num= sc.nextInt();
		int[] unsortedArray =new int[num];
		System.out.println("Enter elements: ");
		for(int i=0;i<num;i++){
			unsortedArray[i]=sc.nextInt();
			System.out.println();
		}
		bubbleSort(unsortedArray,num);
	}

		 static void bubbleSort(int sortedArray[], int num)
		{
			int k, i;
			for(k=0;k<num-1;k++)
			{
				int flag=0;
				for(i=0;i<num-k-1;i++)
				{
					if(sortedArray[i]>sortedArray[i+1])
					{
						int temp = sortedArray[i];
						sortedArray[i]=sortedArray[i+1];
						sortedArray[i+1]=temp;
						flag=1;
					}
				}
				if(flag==0)
					break;
			}
			System.out.print("sorted array: ");
			for(i=0;i<num;i++){
				System.out.print(sortedArray[i]+ " ");
			}
		}




}