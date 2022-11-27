#ifndef BODYINDEX_H
#define BODYINDEX_H


class BodyIndex {
public:
    BodyIndex(float height, float weight);
    float getBMI();

protected:
    float p_height;
    float p_weight;
};

#endif // BODYINDEX_H
