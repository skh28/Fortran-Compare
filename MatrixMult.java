
public class MatrixMult {
			
			public static void main(String[] args) {

			int row = 800;
			int col = 800;
			int[][] firstMatrix = new int[row][col];
			int[][] secondMatrix = new int[row][col];
			int[][] finalMatrix = new int[row][col];
			
			//initializing first and second matrix
			for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
			firstMatrix[i][j] = (i+j)%100;	
			secondMatrix[i][j] = (i+j)%100;
			}
			}
			
			//Print for the first matrix
			System.out.println("First Matrix ============");
			for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
			System.out.print(firstMatrix[i][j] + " ");
			}
			System.out.println();
			}
			
			//Print the second matrix
			System.out.println("Second Matrix =============");
			for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
			System.out.print(secondMatrix[i][j] + " ");
			}
			System.out.println();
			}
						

			long start = System.nanoTime();
			for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
			for (int k = 0; k < 800; k++) {
			finalMatrix[i][j] = finalMatrix[i][j] + firstMatrix[i][k] * secondMatrix[k][j]; //matrix multiplication (Rows * Column)
			}
			}
			}
			long end = System.nanoTime();
			
			//Print function (rows by columns)
			System.out.println("Final Matrix is:");
			for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
			System.out.print(finalMatrix[i][j] + " ");
			}
			System.out.println();
			}
			System.out.printf("%s%d%s\n", "Time is: ", end-start, " nanoseconds");
			}
}
