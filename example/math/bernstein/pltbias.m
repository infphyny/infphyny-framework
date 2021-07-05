#!matlab

bernsteincubic = load('allbernstein.txt');


figure(1);
plot(bernsteincubic(:,1),bernsteincubic(:,2),bernsteincubic(:,1),
bernsteincubic(:,3),bernsteincubic(:,1),bernsteincubic(:,4),bernsteincubic(:,1),bernsteincubic(:,5))
#figure(2)
#plot(bernsteincubic(:,1),bernsteincubic(:,3)) 
#figure(3)
#plot()
#figure(4)
# plot()
#,bernsteincubic(:,4),bernsteincubic(:,5)
#figure(2);
#plot(gain(:,1),gain(:,2))