<img src="icon.png" align="right" >

# The Rudra Guide
Rudra is an Open Source Neural Network with both CPU and GPU Optimization in C language. 
<br>This Library Consist of two modules-:
<br>
*Module-1(Data Preprocessing)*
<br>
*Module-2(Artificial Neural Network)*

## How to Use Module-1 (Data Preprocessing Module)
<br>
<table style="width:100%">
  <tr>
    <th>Function Prototype</th>
     <th>Description</th>
    <th>Arguements and Return Type</th>
    <th>Example</th>
  </tr>
  <tr>
    <td>double **f2m(char *fname, unsigned char delimiter)</td>
    <td>Function to convert .csv file to a 2-d matrix</td>
    <td>Return type-: 2-d Matrix pointer <br> Arguements:<br></td>
    <td></td>
  </tr>
  <tr>
    <td>FILE *m2f(char *fname, double **matrix, unsigned long row,unsigned long col)</td>
    <td>Funtion to convert 2-d matrix to .csv ( For Saving the final .csv file)</td>
    <td>Return Type-: FILE</td>
  </tr>
   <tr>
    <td>void normalization(double **raw_data, size_t m, size_t n, size_t b,enum n_type decision)</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>void delcol(double **mat, unsigned long r, unsigned long c,unsigned long rem)</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>double **split(double **matrix, unsigned long r, unsigned long c,unsigned long si, unsigned long ei, enum bool_ horizontal)</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  
</table>

## How to Use Module-2 (Artificial Neural Network Module)
<br>
<table style="width:100%">
  <tr>
    <th>Function Name</th>
    <th>Usage</th>
    <th>Example</th>
  </tr>
  <tr>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>


