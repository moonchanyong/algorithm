package just_javaplactice;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class re_painting {
	

	  public static void main(String[] args) {
			try(Scanner s = new Scanner(System.in))
			{
				int n = s.nextInt();
				int d = s.nextInt();
				int k = s.nextInt();
				int j = s.nextInt();				
								
				//여기부터 작성해 주세요
				Queue<Integer> q = new LinkedList<Integer>();
				if(d == 1)
				{
				//1 이면 시계방향 
				for(int i = 1 ; i <= n ; i++)
				{
					q.offer(i);
				}
				}
				else
				{// 0 반시계
					q.offer(1);
					for(int i = n ; i > 1 ; i--)
					{
						q.offer(i);
					}					
				}
				
				// 동작부 
				int temp = (int)q.poll();
				q.offer(temp);
				while(q.size() != 1)
				{				
					int size = q.size();
					if(k%size!=0)
					for(int i = 0 ; i < k%size ; i++)
					{
						if(i!=0)
							q.offer(temp);						
						temp = (int)q.poll();
					}
					else
					{
						for(int i = 0 ; i < k ; i++)
						{
							if(i!=0)
								q.offer(temp);						
							temp = (int)q.poll();
						}						
					}
					
					k+=j;
				}
				
				System.out.print(q.peek());
				
			}
	  } 
	
	/*

	  public static void main(String[] args) {
	    try(Scanner s = new Scanner(System.in))
	    {
	      int n = s.nextInt();
	      ArrayList<Integer> x = new ArrayList<>();
	      ArrayList<Integer> y = new ArrayList<>();
	      Stack<Integer> st = new Stack<Integer>();
	      for(int i = 0; i < n; i++)
	      {
	        int a = s.nextInt();
	        int b = s.nextInt();

					//여기부터 작성해 주세요
	    
	        x.add(a);
	        y.add(b);
	        
			}
	      Collections.sort(x);
	      Collections.sort(y);
	      
	      //  () 사전처리 
	      ArrayList<String> ans = new ArrayList<>();	      
	      ans.add("(-, ");
	      int index = 0 ;
	   // // 중처리
	      int i = 0;
	      int j = 0;
	      int cursor = -1;	      
	      int stack= 0;
	      
	      while(true) // 둘다 x랑 y모두 접근 끝날때까지  
	      {
	    	  int may_x = 0 ;
	    	  int may_y = 0;
	    	  boolean check = false ; // 중괄호인지 보는거 
	    	 if(i < n && j < n )
	    	 {
	    		 if(x.get(i) < y.get(j))
	    		 {
	    			cursor = x.get(i);
	    			stack++;
	    			i++;
	    			if(stack%2 == 1)
	    				check = true;
	    		 }
	    		 else if(x.get(i) > y.get(j))
	    		 {
	    			 cursor = y.get(j);
	    			 stack--;
	    			 j++;
		    			if(stack%2 == 0)
		    				check = true;
	    		 }
	    		 else
	    		 {
	    			 cursor = x.get(i);
	    			 for(int ii = i+1 ; ii <= n ;ii++)
	    			 {
		    				if(ii == n) 
		    				{
		    					i = n;
		    					break;
		    				}
	    				 
	    				if(x.get(ii) == x.get(ii-1))
	    					may_x++;
	    				else
	    					{	    		
	    					i = ii;
	    					break;
	    					}

	    					
	    			 }
	    			 
	    			 
	    			 for(int ii = j+1 ; ii <= n ;ii++)
	    			 {
		    				if(ii == n) 
		    				{
		    					j = n;
		    					break;
		    				}
	    				 
		    				if(y.get(ii) == y.get(ii-1))
		    					may_y++;
		    				else
		    				{
		    					j = ii;
		    					break;
		    				}
		    				
	    			 } 
	    			 
	    			 stack += may_x+1;
	    				if(stack%2 == 1)
		    				check = true;
	    				if(stack%2 == 0) // 짝수면 
	    	 			{
	    	 				if(!check)
	    	 				ans.add("["+cursor+", ");
	    	 				else
	    	 				{
	    	 					ans.add("("+cursor+", ");
	    	 				}
	    	 			}
	    	 			else if(stack%2 == 1 && ans.size()-1>=index) // 홀수
	    	 			{
	    	 				if(!check)
	    	 				ans.set(index, ans.get(index)+cursor+"]");
	    	 				else
	    	 				{
	    	 					ans.set(index, ans.get(index)+cursor+")");
	    	 				}
	    	 				index++;
	    	 			}
	    				stack -= (may_y+1);
	    				check = false;
	    				if(stack%2 == 0)
		    				check = true;

	    		 }	    		 
	    		
	    		 
	    		 
	    	 }
	    	 else if(i >= n && j < n )
	    	 {
	    		 
				 cursor = y.get(j);
    			 stack--;
    			 j++;
	    			if(stack%2 == 0)
	    				check = true;
	    	 }
	    	 else if(i < n && j >= n )
	    	 {

	    			cursor = x.get(i);
	    			stack++;
	    			i++;
	    			if(stack%2 == 1)
	    				check = true;

    
	    	 }
	    	 else
	    	 {
	    		 ans.set(index, ans.get(index)+"+"+")");
	    		 break;
	    	 }
	    		 
 			if(stack%2 == 0) // 짝수면 
 			{
 				if(!check)
 				ans.add("["+cursor+", ");
 				else
 				{
 					ans.add("("+cursor+", ");
 				}
 			}
 			else if(stack%2 == 1 && ans.size()-1>=index) // 홀수 , 만약 짝수가 전에 시작되어 있었다면 실행 
 			{
 				if(!check)
 				ans.set(index, ans.get(index)+cursor+"]");
 				else
 				{
 					ans.set(index, ans.get(index)+cursor+")");
 				}
 				index++;
 			}
	    	 
 			
	      }
	       
	     for(int ii = 0 ; ii < ans.size(); ii++)
	     {
	    	 System.out.print(ans.get(ii));
	    	 if(ii != ans.size()-1)
	    	 {
	    		 System.out.print("\n");
	    	 }
	     }
	     
	      
			}
	  }*/
	
	
/*문제 3
    static class rec {
        int x, y, w, h;
        rec(){}
        
        
    }
    
	  public static void main(String[] args) {
			try(Scanner s = new Scanner(System.in))
			{
				 
		        ArrayList<rec> d = new ArrayList<>();
		        ArrayList<Integer> x = new ArrayList<>();
		        ArrayList<Integer> y = new ArrayList<>();

				
				   int ans = 0;
			
			        for (int i = 0; i < 3; i++) {
			            rec temp = new rec();
			            temp.x = s.nextInt();
			            temp.y = s.nextInt();
			            int temp_x = s.nextInt();
			            int temp_y = s.nextInt(); 
			            temp.w = temp_x - temp.x;
			            temp.h = temp_y - temp.y;
			            d.add(temp);

			            x.add(d.get(i).x);
			            x.add(d.get(i).x + d.get(i).w);
			            y.add(d.get(i).y);
			            y.add(d.get(i).y + d.get(i).h);
			        }

			        Collections.sort(x);
			        Collections.sort(y);
// 모든 표면적 1 포함 
			        for (int i = 0; i < x.size() - 1; i++)
			            for (int j = 0; j < y.size() - 1; j++)
			                for (int k = 0; k < 3; k++)
			                    if (x.get(i) >= d.get(k).x && x.get(i + 1) <= d.get(k).x + d.get(k).w &&
			                            y.get(j) >= d.get(k).y && y.get(j + 1) <= d.get(k).y + d.get(k).h) {
			                        ans += (x.get(i + 1) - x.get(i)) * (y.get(j + 1) - y.get(j));
			                        break;
			                    }
			        // 1 빼고 표면적 
				int dec= 0 ;
				
			        for (int i = 0; i < x.size() - 1; i++)
			            for (int j = 0; j < y.size() - 1; j++)
			                for (int k = 1; k < 3; k++)
			                    if (x.get(i) >= d.get(k).x && x.get(i + 1) <= d.get(k).x + d.get(k).w &&
			                            y.get(j) >= d.get(k).y && y.get(j + 1) <= d.get(k).y + d.get(k).h) {
			                        dec += (x.get(i + 1) - x.get(i)) * (y.get(j + 1) - y.get(j));
			                        break;
			                    }
			        System.out.print(ans-dec);
			}

			
	  } // main 종료 
	*/
	

		
		
	}


