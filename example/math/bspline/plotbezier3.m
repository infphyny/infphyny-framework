bezier3basis = load('bezier3_basis.txt');


figure(1);
plot(bezier3basis(:,1),bezier3basis(:,2),
     bezier3basis(:,1),bezier3basis(:,3),
     bezier3basis(:,1),bezier3basis(:,4),
     bezier3basis(:,1),bezier3basis(:,5))
