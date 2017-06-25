is = fopen('otherExperiment2_is_data.out', 'r');
x1 = fscanf(is, '%d,%f', [2, Inf]);
rms = fopen('otherExperiment2_rms_data.out', 'r');
x2 = fscanf(rms, '%d,%f', [2, Inf]);
ims = fopen('otherExperiment2_ims_data.out', 'r');
x3 = fscanf(ims, '%d,%f', [2, Inf]);

plot(x1(1,:), x1(2,:), 's-', 'LineWidth', 0.9, 'Color', [0.4 0.6 0.85]);
hold on
plot(x2(1,:), x2(2,:), 's-', 'LineWidth', 0.9, 'Color', [255/255 128/255 0]);
%plot(x3(1,:), x3(2,:), 's-', 'LineWidth', 0.9, 'Color', [160/255 160/255 160/255]);

xlabel('linked list size');
ylabel('CPU Time (ms)');
legend('insertion sort', 'recursive merge sort', 'iterative merge sort'...
	 , 'Location', 'northwest');
title('running time of different sorting algorithms');


fclose(is);
fclose(rms);
fclose(ims);