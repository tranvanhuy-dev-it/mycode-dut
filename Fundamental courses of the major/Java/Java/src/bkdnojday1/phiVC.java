package bkdnojday1;

import java.util.*;

public class phiVC {

    static long dijkstra(int start, int end, int n, int[][] B, int[] A) {

        long[] dist = new long[n + 1];
        Arrays.fill(dist, Long.MAX_VALUE / 4);
        dist[start] = 0;

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        pq.add(new long[]{0, start});

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            long currentCost = cur[0];
            int u = (int) cur[1];

            if (currentCost > dist[u]) continue;

            for (int v = 1; v <= n; v++) {
                if (B[u][v] == -1) continue;
                long newCost = currentCost + B[u][v];
                if (v != end) {
                    newCost += A[v];
                }
                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.add(new long[]{newCost, v});
                }
            }
        }

        return dist[end];
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] A = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            A[i] = sc.nextInt();
        }
        int[][] B = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                B[i][j] = sc.nextInt();
            }
        }

        while (m-- > 0) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            System.out.println(dijkstra(start, end, n, B, A));
        }
    }
}
