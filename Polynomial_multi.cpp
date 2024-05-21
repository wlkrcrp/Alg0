#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
const double PI = acos(-1);
typedef complex<double> cd;
cd* FFT(cd* S, int N, bool invert) 
{
 cd* A = new cd[N];
 if (N == 1) 
 {
 A[0] = S[0];
 return A;
 } 
 else 
 {
 cd* X = new cd[N / 2];
 cd* Y = new cd[N / 2];
 for (int i = 0; i < N / 2; ++i) {
 X[i] = S[2 * i];
 Y[i] = S[2 * i + 1];
 }
 cd* B = FFT(X, N / 2, invert);
 cd* C = FFT(Y, N / 2, invert);
 delete[] X;
 delete[] Y;
 double theta = -2 * PI / N * (invert ? -1 : 1);
 cd P(1), W(cos(theta), sin(theta));
 for (int r = 0; r < N / 2; ++r) 
 {
 cd term = P * C[r];
 A[r] = B[r] + term;
 A[r + N / 2] = B[r] - term;
 if (invert) {
 A[r] /= 2;
 A[r + N/2] /= 2;
 }
 P = P * W;
 }
 delete[] B;
 delete[] C;
 return A;
 }
}
class polynomial
{
 private:
 int lim;
 cd *coeff;
 public:
 polynomial(int limit)
 {
 lim=limit;
 coeff=new cd[lim];
 }
 ~polynomial() 
 {
 delete[] coeff;
 }
 polynomial operator*(const polynomial& oth) const {
 int N = 1;
 while (N < lim + oth.lim - 1) 
 {
 N=N<<1;
 }
 cd *A = new cd[N];
 for(int i = 0; i < N; ++i){
 if(i < lim)
 A[i] =coeff[i];
 else
 A[i] =0;
 }
 cd *fA = FFT(A, N, false);
 cd* B = new cd[N];
 for(int i = 0; i < N; ++i){
 if(i < oth.lim)
 B[i] = oth.coeff[i];
 else
 B[i] =0;
 }
 cd *fB = FFT(B,N, false);
 
 for(int i = 0; i < N; ++i){
 fA[i] *= fB[i];
 }
 cd *ifft_fA = FFT(fA, N, true);
 polynomial result(lim + oth.lim - 1);
 for (int i = 0; i < result.lim; ++i) {
 result.coeff[i] = ifft_fA[i];
 }
 delete[] fA;
 delete[] fB;
 delete[] A;
 delete[] B;
 delete[]ifft_fA;
 return result;
 }
 cd operator[](int index) const
 {
 return coeff[index];
 }
 friend istream& operator>>(istream& is, polynomial& obj)
 {
 for (int i = 0; i < obj.lim; ++i) 
 {
 int co;
 cout << "Enter coefficient of x^" << i << ": ";
 is >> co;
 obj.coeff[i] = cd(co, 0);
 }
 return is;
 }
 friend ostream& operator<<(ostream& os, const polynomial& obj)
 {
 os<<endl;
 for (int i = 0; i < obj.lim; ++i) 
 {
 os<<"coefficient of x^"<<i<<":";
 os<< obj[i].real()<<endl;
 }
 return os;
 }
 int operator()(int x)const{
 int i=lim-1;
 int p=round(coeff[i].real());
 while(i>0)
 {
 p=p*x+coeff[i-1].real();
 --i;
 }
 return p;
 }
};
int main()
{
 int n1,n2;
 cout<<"enter the size of First polynomial : ";
 cin>>n1;
 polynomial p1(n1);
 cout<<"enter First polynomial : "<<endl;
 cin>>p1;
 cout<<"enter the size of second polynomial : ";
 cin>>n2;
 polynomial p2(n2);
 cout<<"enter second polynomial: "<<endl;
 cin>>p2;
 polynomial Result = p1 * p2;
 cout << "After polynomial multiplication:" << endl;
 cout << endl << "Result: " << Result << endl;
 int x;
 cout<<"Enter value of X:";
 cin>>x;
 cout<<"evaluate value of p:";
 cout<<Result(x);
 return 0;
}

