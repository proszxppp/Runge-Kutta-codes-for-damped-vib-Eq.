#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define points 13131
#define times 7
int main()
{
    float x[times][points],v[times][points],m=20,k=5,c=2;
    float k1,k2,k3,k4,l1,l2,l3,l4,dt=0.02,t[times];
    float rmsd[times],tot[times];
    FILE *xf, *vf, *cf;
//    printf("R-K   m*d^2(x)/dt^2=-c*dx/dt-k*x\n");
//    printf("Please enter m，k，c")；
//    printf("Physically reasonable parameters")；
//    printf("Example : m=10,k=10,c=2");
//    scanf("%f%f%f",&m,&k,&c); 
    int i=1,j;

    xf=fopen("x.dat","w");
    vf=fopen("v.dat","w");
    t[0]=0.02;
    t[1]=0.1;
    
    for(i=2;i<times;i++){
		    t[i]=i-1;
	            }

  for(j=0;j<times;j++){
  		     dt=t[j];
		     rmsd[j]=0;
		     x[j][0]=5;
		     v[j][0]=0;
      	               fprintf(xf,"\n%f%f%f\n",dt,dt,dt);
      	               fprintf(vf,"\n%f%f%f\n",dt,dt,dt);
		    for(i=0;i<points;i++){
                	        k1=v[j][i];
	                        l1=-c/m*v[j][i]-k/m*x[j][i];
       	       		        k2=v[j][i]+dt*l1/2;
		       	        l2=-c/m*(v[j][i]+dt/2*l1)-k/m*(x[j][i]+dt/2*k1);
       	                        k3=v[j][i]+dt*l2/2;
       	       		        l3=-c/m*(v[j][i]+dt/2*l2)-k/m*(x[j][i]+dt/2*k2);
       		                k4=v[j][i]+dt*l3;
   	           	        l4=-c/m*(v[j][i]+dt*l3)-k/m*(x[j][i]+dt*k3);
       		                x[j][i+1]=x[j][i]+dt/6*(k1+k2*2+k3*2+k4);
      	 	                v[j][i+1]=v[j][i]+dt/6*(l1+2*l2+2*l3+l4);
	                                 }
	    for(i=0;i<points;i++){
	       	               fprintf(xf,"%f\t%f\n",dt*i,x[j][i]);
	       	               fprintf(vf,"%f\t%f\n",dt*i,v[j][i]);
				rmsd[j]=rmsd[j]+(x[j][i]-x[0][i])*(x[j][i]-x[0][i]);
//tot[j]=tot[j]+(x[j][i])*(x[j][i]);
//    		                  fprintf(cf,"%f\t%f\n",dt*i,corr[i]);
      	                 }
//			rmsd[j]/=points;
//			rmsd[j]=sqrt(rmsd[j]);
//printf("%f\t%f\t%f\n",dt,rmsd[j],tot[j]);
                     }
    fclose(xf);
    fclose(vf);
//    fclose(cf);
//    getchar();
}  
