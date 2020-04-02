

public class Encrypt
{
  public static void main( String args[]) throws Exception
  {
    if( args.length != 2) {
      System.err.println( "Usage: Encrypt key plaintext");
      System.exit(1);
    }
    int K = Integer.parseInt( args[0], 2);
    SDES A = new SDES( K);
    int m = Integer.parseInt( args[1], 2);

    m = A.encrypt( m);
    SDES.printb( m, 8);
    System.out.println();
  }
}

/*

sample run:

% java Encrypt 0000011111 11111111
11100001
% java Decrypt 0000011111 11100001
11111111
%

*/
