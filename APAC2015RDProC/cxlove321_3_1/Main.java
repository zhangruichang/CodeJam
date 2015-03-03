import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        int t = 1;
        while ((t --) > 0)
            solver.solve(in, out);
        out.close();
    }
}

class Task{ 
    static int N = 105;
    static BigInteger c[][] = new BigInteger[N][N];
    static BigInteger fac[] = new BigInteger [N * 2];
    void solve (InputReader cin , PrintWriter cout) {
        fac[0] = BigInteger.ONE;
        for (int i = 1 ; i < N * 2 ; i ++) {
            fac[i] = fac[i - 1].multiply(BigInteger.valueOf(i));
        }
        for (int i = 1 ; i < N ; i ++) {
            c[i][0] = BigInteger.ONE;
            for (int j = 1 ; j <= i ; j ++) {
                c[i][j] = fac[i + j].divide(fac[i].multiply (fac[j]));
                c[i][j] = c[i][j].subtract(fac[i + j].divide(fac[j - 1].multiply (fac[i + 1])));
            }
        }
        int t = cin.nextInt ();
        for (int cas = 1 ; cas <= t ; cas ++) {
            int n = cin.nextInt ();
            BigInteger k = cin.nextBigInteger();
            cout.print("Case #" + cas + ": ");
            if (c[n][n].compareTo(k) < 0) {
                cout.println ("Doesn't Exist!");
                continue;
            }
            int left = n , right = n;
            for (int i = 0 ; i < 2 * n ; i ++) {
                // '('
                if (left > 0) {
                    if (c[right][left - 1].compareTo(k) >= 0) {
                        left --;
                        cout.print("(");
                        continue;
                    }
                    k = k.subtract(c[right][left - 1]);
                }
                cout.print(")");
                right --;
            }
            cout.println ("");
        }
    }  
}  
class InputReader {  
    public BufferedReader reader;  
    public StringTokenizer tokenizer;  
    public InputReader(InputStream stream) {  
        reader = new BufferedReader(new InputStreamReader(stream));  
        tokenizer = null;  
    }  
    public String next() {  
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {  
            try {  
                tokenizer = new StringTokenizer(reader.readLine());  
            } catch (IOException e) {  
                throw new RuntimeException(e);  
            }  
        }  
        return tokenizer.nextToken();  
    }  
    public int nextInt() {  
        return Integer.parseInt(next());  
    }  
    public long nextLong() {  
        return Long.parseLong(next());  
    }  
    public double nextDouble() {  
        return Double.parseDouble(next());  
    }  
    public BigInteger nextBigInteger() {  
        return new BigInteger(next());  
    }  
}  