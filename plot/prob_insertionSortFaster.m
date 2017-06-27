probability_rms = fopen('.prob_insertionSortFaster_data_rms', 'r');
prob_rms = fscanf(probability_rms, '%d,%f', [2, Inf]);
probability_ims = fopen('.prob_insertionSortFaster_data_ims', 'r');
prob_ims = fscanf(probability_ims, '%d,%f', [2, Inf]);
probability_qs = fopen('.prob_insertionSortFaster_data_qs', 'r');
prob_qt = fscanf(probability_qs, '%d,%f', [2, Inf]);

fclose(probability_rms);
fclose(probability_ims);
fclose(probability_qs);

b1 = bar(prob_rms(1,:), prob_rms(2,:), 1);
xlim([1 100]);
%b1.FaceColor = [0.4 0.6 0.85];
b1.FaceColor = [67/255 110/255 238/255];
b1.BarWidth = 1;

hold on
b2 = bar(prob_ims(1,:), prob_ims(2,:), 1);
b2.FaceAlpha = 0.45;
%b2.FaceColor = [137/255 104/255 204/255];
b2.FaceColor = [181/255 181/255 181/255];

b3 = bar(prob_qt(1,:), prob_qt(2,:), 1);
b3.FaceAlpha = 0.45;
b3.FaceColor = [54/255 54/255 28/255];

legend('insertion sort is faster than recursive mergesort' ...
     , 'insertion sort is faster than iterative mergesort' ...
     , 'insertion sort is faster than quick sort');
xlabel('linked list size');
ylabel('probability');
title('probability that insertion sort is faster with 100000 sample points');
