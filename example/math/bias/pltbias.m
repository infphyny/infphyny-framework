#!matlab

bias = load('bias.txt');
gain = load('gain.txt');

figure(1);
plot(bias(:,1),bias(:,2))

figure(2);
plot(gain(:,1),gain(:,2))