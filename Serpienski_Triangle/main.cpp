#include <SFML/Graphics.hpp>
#include <optional>
#include <cmath>
#include <random>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode({800, 600}), "Sierpinski Triangle");
    window.setFramerateLimit(10);

    float size = 400.f;

    ConvexShape triangle;
    triangle.setPointCount(3);

    triangle.setPoint(0, Vector2f(0.f, size * sqrt(3.f) / 2.f));
    triangle.setPoint(1, Vector2f(size, size * sqrt(3.f) / 2.f));
    triangle.setPoint(2, Vector2f(size / 2.f, 0.f));

    triangle.setPosition(Vector2f(200.f, 100.f));

    triangle.setFillColor(Color::Transparent);
    triangle.setOutlineColor(Color::White);
    triangle.setOutlineThickness(2.f);

    Vector2f A = triangle.getTransform().transformPoint(
        triangle.getPoint(0)
    );

    Vector2f B = triangle.getTransform().transformPoint(
        triangle.getPoint(1)
    );

    Vector2f C = triangle.getTransform().transformPoint(
        triangle.getPoint(2)
    );

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> randomVertex(0, 2);

    Vector2f P(400.f, 300.f);

    int totalPoints = 100;

    cout<<"Enter Number of Points:";
    cin>>totalPoints;

    int generatedPoints = 0;

    int pointsPerFrame = 10;
    cout<<"Enter Points per Frame:";
    cin>>pointsPerFrame;

    VertexArray points(PrimitiveType::Points);

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->getIf<Event::Closed>())
            {
                window.close();
            }
        }

        for (int i = 0; i < pointsPerFrame && generatedPoints < totalPoints; i++)
        {
            int choice = randomVertex(rng);

            if (choice == 0)
                P = (P + A) / 2.f;
            else if (choice == 1)
                P = (P + B) / 2.f;
            else
                P = (P + C) / 2.f;

            Vertex point;
            point.position = P;
            point.color = Color::Red;
            points.append(point);

            generatedPoints++;
        }

        window.clear(Color::Black);

        window.draw(triangle);
        window.draw(points);

        window.display();
    }

    return 0;
}