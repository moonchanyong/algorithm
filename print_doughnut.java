package just_javaplactice;

import java.util.Random;
import java.util.Scanner;
// 도넛 좌표 출력하기 _단위벡터사용 
public class print_doughnut {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Random ra = new Random();
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		double r1 = 2;
		double r2 = 0.5;
		// 2인 원 그리고 + 0.5
		
		for(int i = 0  ; i <input ; )
		{
			double x = (Math.random()*2);
			double y = (Math.random()*2);
			if((Math.pow(x, 2) + Math.pow(y, 2)) > 4 )
			{
				continue;
			}
			i++;
			double unit_vec_x = x/Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
			double unit_vec_y = y/Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));	
			System.out.printf("%.3f %.3f %.3f\n ",x+unit_vec_x*0.5,y+unit_vec_y*0.5, Math.sqrt(Math.pow(x*unit_vec_x, 2)+Math.pow(y*unit_vec_y, 2)));
			System.out.printf("-%.3f -%.3f %.3f\n ",x+unit_vec_x*0.5,y+unit_vec_y*0.5, Math.sqrt(Math.pow(x*unit_vec_x, 2)+Math.pow(y*unit_vec_y, 2)));
			System.out.printf("-%.3f %.3f %.3f\n ",x+unit_vec_x*0.5,y+unit_vec_y*0.5, Math.sqrt(Math.pow(x*unit_vec_x, 2)+Math.pow(y*unit_vec_y, 2)));
			System.out.printf("%.3f -%.3f %.3f\n ",x+unit_vec_x*0.5,y+unit_vec_y*0.5, Math.sqrt(Math.pow(x*unit_vec_x, 2)+Math.pow(y*unit_vec_y, 2)));
		}
		
		
		
	}

}
