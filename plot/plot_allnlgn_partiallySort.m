nms = fopen('.plot_allnlgn_partiallySort_data_nms', 'r');
x1 = fscanf(nms, '%d,%f', [2, Inf]);
rms = fopen('.plot_allnlgn_partiallySort_data_rms', 'r');
x2 = fscanf(rms, '%d,%f', [2, Inf]);
ims = fopen('.plot_allnlgn_partiallySort_data_ims', 'r');
x3 = fscanf(ims, '%d,%f', [2, Inf]);
qs = fopen('.plot_allnlgn_partiallySort_data_qs', 'r');
x4 = fscanf(qs, '%d,%f', [2, Inf]);
fclose(nms);
fclose(rms);
fclose(ims);
fclose(qs);


plot(x2(1,:), x2(2,:), 's-', 'LineWidth', 0.9, 'Color', [255/255 128/255 0]);
hold on
plot(x3(1,:), x3(2,:), 's-', 'LineWidth', 0.9, 'Color', [151/255 151/255 151/255]);
plot(x1(1,:), x1(2,:), 's-', 'LineWidth', 0.9, 'Color', [0.4 0.6 0.85]);
plot(x4(1,:), x4(2,:), 's-', 'LineWidth', 0.9, 'Color', [1/255 1/255 1/255]);


xlabel('linked list size');
ylabel('CPU Time (ms)');
legend('recursive merge sort'...
     , 'iterative merge sort'...
     , 'natural merge sort'...
	 , 'quick sort'...
	 , 'Location', 'northwest');
title('running time of different sorting algorithms');
