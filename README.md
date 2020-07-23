# SCL-Jogjas-Island
Our team solution for Shopee Code League competition.

# Week 1 - Order Brushing

## Solution
We use sliding window concept and some data manipulation.
## Result
Our solution manages to get full score (1.0) on the private leaderboard. You can run solution.cpp to get the submission CSV.

# Week 2 - Product Detection
In this competition, a multiple image classification model needs to be built. There are ~100k images within 42 different categories, including essential medical tools like masks, protective suits and thermometers, home & living products like air-conditioner and fashion products like T-shirts, rings, etc. For the data security purpose the category names will be desensitized. The evaluation metrics is top-1 accuracy.

## Solution
We use three models (EfficinetNet-B4, EfficientNet-B5, and Xception) with no data augmentation and unfreeze last few layers for each model.

## Result
This solution manages to get 0.83922 accuracy in the private leaderboard (11th place out of 823 teams). 

## Pre-trained Models

You can get our submission CSV by running Inference.ipynb with our pretrained models in [here](https://www.kaggle.com/lan666as/pretrainedweight).