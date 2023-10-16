import java.util.*;
class GFG {
static void lcm(int seed, int mod, int multiplier,
					int inc, int[] randomNums,
					int noOfRandomNum)
	{

		randomNums[0] = seed;

	
		for (int i = 1; i < noOfRandomNum; i++) {

			// Follow the linear congruential method
			randomNums[i]
				= ((randomNums[i - 1] * multiplier) + inc)
				% m;
		}
	}

	// Driver code
	public static void main(String[] args)
	{

		// Seed value
		int seed = 5;

		// Modulus parameter
		int mod = 7;

		// Multiplier term
		int multiplier = 3;
		int inc = 3;int noOfRandomNum = 10;

		// To store random numbers
		int[] randomNums = new int[noOfRandomNum];

		lcm(seed, mod, multiplier, inc, randomNums,
			noOfRandomNum);

		for (int i = 0; i < noOfRandomNum; i++) {
			System.out.print(randomNums[i] + " ");
		}
	}
}
