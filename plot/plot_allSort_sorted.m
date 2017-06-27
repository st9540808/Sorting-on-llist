is = fopen('.plot_allSort_sorted_data_is', 'r');
x1 = fscanf(is, '%d,%f', [2, Inf]);
rms = fopen('.plot_allSort_sorted_data_rms', 'r');
x2 = fscanf(rms, '%d,%f', [2, Inf]);
ims = fopen('.plot_allSort_sorted_data_ims', 'r');
x3 = fscanf(ims, '%d,%f', [2, Inf]);
nms = fopen('.plot_allSort_sorted_data_nms', 'r');
x4 = fscanf(nms, '%d,%f', [2, Inf]);
qs = fopen('.plot_allSort_sorted_data_qs', 'r');
x5 = fscanf(qs, '%d,%f', [2, Inf]);
fclose(is);
fclose(rms);
fclose(ims);
fclose(nms);
fclose(qs);


plot(x1(1,:), x1(2,:), 's-', 'LineWidth', 0.9, 'Color', [0.4 0.6 0.85]);
hold on
plot(x2(1,:), x2(2,:), 's-', 'LineWidth', 0.9, 'Color', [255/255 128/255 0]);
plot(x3(1,:), x3(2,:), 's-', 'LineWidth', 0.9, 'Color', [169/255 169/255 169/255]);
plot(x4(1,:), x4(2,:), 's-', 'LineWidth', 0.9, 'Color', [124/255 252/255 0/255]);
plot(x5(1,:), x5(2,:), 's-', 'LineWidth', 0.9, 'Color', [1/255 1/255 1/255]);


xlabel('linked list size');
ylabel('CPU Time (ms)');
legend('insertion sort' ...
     , 'recursive merge sort'...
     , 'iterative merge sort'...
     , 'natural merge sort'...
     , 'quick sort'...
	 , 'Location', 'northwest');
title('running time of different sorting algorithms');
