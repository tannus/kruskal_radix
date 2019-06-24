#!/bin/bash

VERSION=$1

(cat kruskal_radix/results/"time"/merge1) &>> merge_final
(cat kruskal_radix/results/"time"/merge2) &>> merge_final
(cat kruskal_radix/results/"time"/merge3) &>> merge_final
(cat kruskal_radix/results/"time"/merge4) &>> merge_final
(cat kruskal_radix/results/"time"/merge5) &>> merge_final
(cat kruskal_radix/results/"time"/merge6) &>> merge_final
(cat kruskal_radix/results/"time"/merge7) &>> merge_final
(cat kruskal_radix/results/"time"/merge8) &>> merge_final
(cat kruskal_radix/results/"time"/merge9) &>> merge_final
(cat kruskal_radix/results/"time"/mergeA) &>> merge_final
(cat kruskal_radix/results/"time"/mergeB) &>> merge_final
(cat kruskal_radix/results/"time"/mergeC) &>> merge_final
(cat kruskal_radix/results/"time"/radix1) &>> radix_final
(cat kruskal_radix/results/"time"/radix2) &>> radix_final
(cat kruskal_radix/results/"time"/radix3) &>> radix_final
(cat kruskal_radix/results/"time"/radix4) &>> radix_final
(cat kruskal_radix/results/"time"/radix5) &>> radix_final
(cat kruskal_radix/results/"time"/radix6) &>> radix_final
(cat kruskal_radix/results/"time"/radix7) &>> radix_final
(cat kruskal_radix/results/"time"/radix8) &>> radix_final
(cat kruskal_radix/results/"time"/radix9) &>> radix_final
(cat kruskal_radix/results/"time"/radixA) &>> radix_final
(cat kruskal_radix/results/"time"/radixB) &>> radix_final
(cat kruskal_radix/results/"time"/radixC) &>> radix_final

cp merge_final res/merge/$VERSION
cp radix_final res/radix/$VERSION
rm merge_final
rm radix_final
