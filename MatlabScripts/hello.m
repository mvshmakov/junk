Fs =4000*26;
T = 1/Fs;
n = 45;
t = (0:T:1);
 
Y1 = sin(2*pi*100*13*t)+sawtooth(2*pi*50*13*t,0.5);
plot(t,Y1,'o');
xlim([0 0.008]);
title('Signal');
 
l2=20000;
S=fft(Y1);
K2=abs(S/l2);
K1=K2(1:(l2/2+1))/l2;
K1(2:end-1)=2*K1(2:end-1);
f=Fs*(0:(l2/2))/l2;
figure(2)
plot(f,K1);
 
y = downsample(Y1,n);
t0 = (0:T*n:1);
figure(3)
plot(t0,y,'o');
title('Downsample');
xlim([0 0.008]);
 
y1=decimate(Y1,n,27,'fir');
[l3,l4]=size(y1);
t1=(0:l4-1)*T*n;
figure(4)
plot(t1,y1,'o');
title('Decimate');
xlim([0 0.008]);
 
S=fft(y1);
P2=abs(S/l4);
P1=P2(1:(l4/2+1))/l4;
P1(2:end-1)=2*P1(2:end-1);
f=Fs*(0:(l4/2))/l4;
figure(5)
plot(f,P1);
 
X1=interp1(t0,y,t,'spline');
figure(6);
plot(t0,y,'o',t,X1,':.');
xlim([0 0.008]);
 
f=getframe;
[im,map]=rgb2ind(f.cdata,256);
im(1,1,1,50)=0;
figure(7)
 
for n = 1:1:50
    % y2 = downsample(Y1,n);
    % t0 = (0:T*n:1);
    % plot(t0,y2,'o');
    % nLeg = num2str(n);
    % legend(nLeg);
    % title('Downsample');
    % xlim([0 0.008]);
 
    y1=decimate(Y1,n,27,'fir');
    [l3,l4]=size(y1);
    S=fft(y1);
    P2=abs(S/l4);
    P1=P2(1:(l4/2+1))/l4;
    P1(2:end-1)=2*P1(2:end-1);
    f=Fs*(0:(l4/2))/l4;
    plot(f,P1);
    nLeg = num2str(n);
    legend(nLeg);
    ylim([0 0.0004]);
    xlim([0 55000]);
 
    % y1=decimate(Y1,n,27,'fir');
    % [l3,l4]=size(y1);
    % t1=(0:l4-1)*T*n;
    % plot(t1,y1,'o');
    % nLeg = num2str(n);
    % legend(nLeg);
    % title('Decimate');
    % xlim([0 0.008]);
 
    % y2 = downsample(Y1,n);
    % t0 = (0:T*n:1);
    % X1=interp1(t0,y2,t,'spline');
    % plot(t0,y2,'o',t,X1,':.');
    % nLeg = num2str(n);
    % legend(nLeg);
    % xlim([0 0.008]);
    
    f=getframe;
    im(:,:,1,n)=rgb2ind(f.cdata,map);
end
 
imwrite(im,map,'test.gif','Delaytime',0,'Loopcount',inf)
 
 
 
