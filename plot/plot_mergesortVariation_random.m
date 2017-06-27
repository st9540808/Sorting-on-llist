nms = fopen('.plot_allnlgn_random_data_nms', 'r');
x1 = fscanf(nms, '%d,%f', [2, Inf]);
rms = fopen('.plot_allnlgn_random_data_rms', 'r');
x2 = fscanf(rms, '%d,%f', [2, Inf]);
ims = fopen('.plot_allnlgn_random_data_ims', 'r');
x3 = fscanf(ims, '%d,%f', [2, Inf]);
fclose(nms);
fclose(rms);
fclose(ims);


plot(x2(1,:), x2(2,:), 's-', 'LineWidth', 0.9, 'Color', [255/255 128/255 0]);
hold on
plot(x3(1,:), x3(2,:), 's-', 'LineWidth', 0.9, 'Color', [88/255 88/255 88/255]);
plot(x1(1,:), x1(2,:), 's-', 'LineWidth', 0.9, 'Color', [0.4 0.6 0.85]);


xlabel('linked list size');
ylabel('CPU Time (ms)');
legend('recursive merge sort'...
     , 'iterative merge sort'...
     , 'natural merge sort'...
	 , 'Location', 'northwest');
title('running time of different sorting algorithms');
