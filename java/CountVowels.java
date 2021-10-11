import java.util.Scanner;
public class CountVowels {
    public static void main(String args[]){
        int count = 0;
        System.out.print("Enter a sentence : ");
        Scanner input = new Scanner(System.in);
        //get user input and assign it to sentence variable
        String sentence = input.nextLine();

        //On each iteration get one character and checks it
        for (int i=0 ; i<sentence.length(); i++){
            char ch = sentence.charAt(i);
            if(ch == 'a'|| ch == 'e'|| ch == 'i'
                    ||ch == 'o' ||ch == 'u'){
                count ++;
            }
        }
        System.out.println("Number of vowels "+count);
    }
}
