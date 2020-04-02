

public class Decrypt
{
  public static void main( String args[]) throws Exception
  {
    if( args.length != 2) {
      System.err.println( "Usage: Decrypt key plaintext");
      System.exit(1);
    }
   
    int K = Integer.parseInt( args[0], 2);
    SDES A = new SDES( K);
    int m = Integer.parseInt( args[1], 2);

 
    m = A.decrypt( m);
    SDES.printb( m, 8);
    System.out.println();
  }
}


