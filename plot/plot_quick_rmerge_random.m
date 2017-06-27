rms = fopen('.plot_allnlgn_random_data_rms', 'r');
x2 = fscanf(rms, '%d,%f', [2, Inf]);
qs = fopen('.plot_allnlgn_random_data_qs', 'r');
x4 = fscanf(qs, '%d,%f', [2, Inf]);
fclose(rms);
fclose(qs);


plot(x2(1,:), x2(2,:), 's-', 'LineWidth', 0.9, 'Color', [255/255 128/255 0]);
hold on
plot(x4(1,:), x4(2,:), 's-', 'LineWidth', 0.9, 'Color', [1/255 1/255 1/255]);


xlabel('linked list size');
ylabel('CPU Time (ms)');
legend('recursive merge sort'...
	 , 'quick sort'...
	 , 'Location', 'northwest');
title('running time of different sorting algorithms');
