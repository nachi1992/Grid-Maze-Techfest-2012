int near(int i,int j)
{
if(a[i][j][0]==100)
	return 100;
else if(a[i][j][0]==30)
	{
		a[i][j][0]=100;
		return 100;
	}
else if(a[i][j][0]==0)
	return 0;
else 
{
	int f,b,c,d,e,min;
	f=a[i][j-1][0];
	b=a[i][j+1][0];
	c=a[i-1][j][0];
	d=a[i+1][j][0];
	e=a[a[i][j][1]][a[i][j][2]][0];
		min=f;
		if(b<f)
		min=b;
		if(c<min)
		min=c;
		if(d<min)
		min=d;
		if(e<min)
		min=e;
	if(min==100)
	{
		a[i][j][0]=100;
		return 100;
	}
	else
	{
		a[i][j][0]=min+1;
		return min+1;
	}
}
}
void findpath(void)
{
int f,b,c,d,e,min,bx,by;
	f=a[x][y-1][0];
	b=a[x][y+1][0];
	c=a[x-1][y][0];
	d=a[x+1][y][0];
	e=a[a[x][y][1]][a[x][y][2]][0];
		min=f;
			if(ori_m==1)
			path[pointer]='R';
			if(ori_m==2)
			path[pointer]='S';
			if(ori_m==3)
			path[pointer]='L';
			if(ori_m==4)
			path[pointer]='U';
		
		if(b<f)
		{
			min=b;
			if(ori_m==1)
			path[pointer]='L';
			if(ori_m==2)
			path[pointer]='U';
			if(ori_m==3)
			path[pointer]='R';
			if(ori_m==4)
			path[pointer]='S';
		}
		
		if(c<min)
		{
			min=c;
			if(ori_m==1)
			path[pointer]='U';
			if(ori_m==2)
			path[pointer]='R';
			if(ori_m==3)
			path[pointer]='S';
			if(ori_m==4)
			path[pointer]='L';
		}
		if(d<min)
		{
			min=d;
			if(ori_m==1)
			path[pointer]='S';
			if(ori_m==2)
			path[pointer]='L';
			if(ori_m==3)
			path[pointer]='U';
			if(ori_m==4)
			path[pointer]='R';
		}
		if(e<min)
		{
			min=e;
			bx=a[x][y][1]-x;
			by=a[x][y][2]-y;
			if(bx==1 && by==1)
			{
				if(bridge[x][y][2]==1)
				{
					if(ori_m==1)
					{
						path[pointer]='L';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==2)
					{
						path[pointer]='U';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==3)
					{
						path[pointer]='R';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==4)
					{
						path[pointer]='S';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					ori_m=1;
				}
				if(bridge[x][y][2]==2)
				{
					if(ori_m==1)
					{
						path[pointer]='S';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==2)
					{
						path[pointer]='L';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==3)
					{
						path[pointer]='U';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==4)
					{
						path[pointer]='R';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					ori_m=4;
				}
				x=x+1;
				y=y+1;
			}
			if(bx==1 && by==-1)
			{
				if(bridge[x][y][2]==1)
				{
					if(ori_m==1)
					{
						path[pointer]='R';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==2)
					{
						path[pointer]='S';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==3)
					{
						path[pointer]='L';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==4)
					{
						path[pointer]='U';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					ori_m=1;
				}
				if(bridge[x][y][2]==2)
				{
					if(ori_m==1)
					{
						path[pointer]='S';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==2)
					{
						path[pointer]='L';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==3)
					{
						path[pointer]='U';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==4)
					{
						path[pointer]='R';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					ori_m=2;
				}
				x=x+1;
				y=y-1;
			}
			if(bx==-1 && by==1)
			{
				if(bridge[x][y][2]==1)
				{
					if(ori_m==1)
					{
						path[pointer]='L';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==2)
					{
						path[pointer]='U';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==3)
					{
						path[pointer]='R';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==4)
					{
						path[pointer]='S';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					ori_m=3;
				}
				if(bridge[x][y][2]==2)
				{
					if(ori_m==1)
					{
						path[pointer]='U';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==2)
					{
						path[pointer]='R';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==3)
					{
						path[pointer]='S';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==4)
					{
						path[pointer]='L';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					ori_m=4;
				}
				x=x-1;
				y=y+1;
			}	
			if(bx==-1 && by==-1)
			{
				if(bridge[x][y][2]==1)
				{
					if(ori_m==1)
					{
						path[pointer]='R';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==2)
					{
						path[pointer]='S';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==3)
					{
						path[pointer]='L';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					if(ori_m==4)
					{
						path[pointer]='U';
						path[pointer+1]='R';
						path[pointer+2]='R';
					}
					ori_m=3;
				}
				if(bridge[x][y][2]==2)
				{
					if(ori_m==1)
					{
						path[pointer]='U';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==2)
					{
						path[pointer]='R';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==3)
					{
						path[pointer]='S';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					if(ori_m==4)
					{
						path[pointer]='L';
						path[pointer+1]='L';
						path[pointer+2]='L';
					}
					ori_m=2;
				}
				x=x-1;
				y=y-1;
			}
			pointer=pointer+3;
		}
		if(f==min)
		{
			ori_m=2;	
			pointer++;
			y=y-1;
		}
		else if(b==min)
		{
			ori_m=4;
			pointer++;
			y=y+1;
		}
		else if(c==min)
		{
			ori_m=3;
			pointer++;
			x=x-1;
		}
		else if(d==min)
		{
			ori_m=1;
			pointer++;
			x=x+1;
		}
		
}


