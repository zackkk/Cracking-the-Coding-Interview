/* Write a method to generate a random number between 1 and 7, 
   given a method that generates a random number between 1 and 5 
   (i.e., implement rand7() using rand5()). */


class solution_19_10 {

public:
	int rand5() { 
		// ...
	}

	int rand7(){
		while(true){
			int tmp = (rand5() - 1) * 5 + (rand5() - 1); // generate uniformly distributed numbers
			//if(tmp >= 1 && tmp <= 7) 
			//	return tmp;
			if(tmp < 21)
				return tmp % 7 + 1;
		}
	}
};