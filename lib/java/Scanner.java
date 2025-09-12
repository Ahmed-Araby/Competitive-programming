  private class Scanner {
      private final BufferedReader br;
      private StringTokenizer st;

      public Scanner() {
          final InputStreamReader sr = new InputStreamReader(System.in);
          br = new BufferedReader(sr);
      }

      private String nextToken() throws IOException {
          while(st == null || !st.hasMoreTokens()) {
              st = new StringTokenizer(br.readLine());
          }
          return st.nextToken();
      }

      public int nextInt() throws IOException{
          return Integer.parseInt(nextToken());
      }
  }
