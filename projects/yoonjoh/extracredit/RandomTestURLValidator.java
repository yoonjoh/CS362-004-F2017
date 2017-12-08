import junit.framework.TestCase;
import java.util.Random;

public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }

    public void testRandom1(ResultPair[] scheme)
   {	
	   System.out.println("\n\n Random Testing: SCHEME \n");
	   Random rand = new Random();
	   int  n = rand.nextInt(2);
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String authority = "www.amazon.com";
	   String url;
	   boolean result;

	   for (int i=0; i < 10; i++) {
		   char c = (char)(rand.nextInt(26) + 'a');
		   url = c + scheme[n].item + authority;
		   System.out.printf(url+" ");
		   result = urlVal.isValid(url);
		   if (result == scheme[n].valid){
			   System.out.printf("isValid passed\n");
		   }
		   else {
			   System.out.printf("isValid failed\n");
		   }
	   }
   }
	   
   
   public void testRandom2()
   {
	   System.out.println("\n\n Random Testing: AUTHORITY \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   Random rand = new Random();
	   int  length = rand.nextInt(15);
	   String scheme = "http://www.";
	   String url;
	   
	   for(int i = 0; i < 10; i++) {
		   char c = (char)(rand.nextInt(26) + 'a');
		   url = scheme + c;
		   for(int j = 0; j < length; j++) {
			   c = (char)(rand.nextInt(26) + 'a');
			   scheme += c;
		   }
		   System.out.printf(url+".com ");
		   if (urlVal.isValid(url+".com")) {
			   System.out.printf("isValid passed\n");
		   }
		   else {
			   System.out.printf("isValid failed\n");
		   }
	   }

	   
   }
   
   public void testRandom3()
   {
	   System.out.println("\n\n Random Testing: PATH \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   Random rand = new Random();
	   int  length = rand.nextInt(15);
	   String base = "http://www.amazon.com/";
	   String url;
	   
	   for(int i = 0; i < 10; i++) {
		   char c = (char)(rand.nextInt(26) + 'a');
		   url = base + c;
		   for(int j = 0; j < length; j++) {
			   c = (char)(rand.nextInt(26) + 'a');
			   base += c;
		   }
		   System.out.printf(url+" ");
		   if (urlVal.isValid(url)) {
			   System.out.printf("isValid passed\n");
		   }
		   else {
			   System.out.printf("isValid failed\n");
		   }
	   }
	   
   }
   
   
   public void testRandom4()
   {
	   System.out.println("\n\n Random Testing: PORT \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String base = "http://www.amazon.com:";
	   Random rand = new Random();
	   String url;
	   
	   for(int i = 0; i < 10; i++) {
		   int portNumber = rand.nextInt(1000);
		   url = base + portNumber;
		   System.out.printf(url+" ");
		   if (urlVal.isValid(url+"")) {
			   System.out.printf("isValid passed\n");
		   }
		   else {
			   System.out.printf("isValid failed\n");
		   }
	   }
   }
   
   
   public void testRandom5(ResultPair[] query) {
	   System.out.println("\n\n Random Testing: QUERY \n");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   Random rand = new Random();
	   String base = "http://www.amazon.com/path";
	   String url;
	   
	   for (int i=0; i < 10; i++) {
		   int  n = rand.nextInt(2);
		   char c = (char)(rand.nextInt(26) + 'a');
		   url = base + query[n].item + c;
		   System.out.printf(url+" ");
		   if (urlVal.isValid(url)){
			   System.out.printf("isValid passed\n");
		   }
		   else {
			   System.out.printf("isValid failed\n");
		   }
	   }
   }
   

   
   public static void main(String[] args) {
	
	   UrlValidatorTest tester = new UrlValidatorTest("test1");
	   
	   
	   ResultPair[] scheme = {new ResultPair("http://", true),
			   					new ResultPair("https://", true)}; 
	   
	   
	   ResultPair[] query = {new ResultPair("?query=", true),
			   				new ResultPair("?q=", true),

	   };
	   
	   tester.testRandom1(scheme);
	   tester.testRandom2();
	   tester.testRandom3();
	   tester.testRandom4();
	   tester.testRandom5(query);
   }
   
}

