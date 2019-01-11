#pragma once

#include <vector>
#include <string>

#include <chaiscript/chaiscript.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/System.hpp>


namespace chaiscript {
  namespace extras {
	namespace sfml {

		/**
		 * Register a ChaiScript module with sf::System.
		 */
		ModulePtr addsfSystem(ModulePtr m = std::make_shared<Module>()) {
			// sf::Clock.
			m->add(user_type<sf::Clock>(), "Clock");
			m->add(constructor<sf::Clock()>(), "Clock");
			m->add(fun(&sf::Clock::getElapsedTime), "getElapsedTime");
			m->add(fun(&sf::Clock::restart), "restart");

			// sf::Time.
			m->add(user_type<sf::Time>(), "Time");
			m->add(constructor<sf::Time()>(), "Time");
			m->add(fun(&sf::Time::asSeconds), "asSeconds");
			m->add(fun(&sf::Time::asMilliseconds), "asMilliseconds");
			m->add(fun(&sf::Time::asMicroseconds), "asMicroseconds");

			// sf::Vector2f.
			m->add(user_type<sf::Vector2f>(), "Vector2f");
			m->add(fun(&sf::Vector2f::x), "x");
			m->add(fun(&sf::Vector2f::y), "y");
			m->add(constructor<sf::Vector2f()>(), "Vector2f");
			m->add(constructor<sf::Vector2f(float, float)>(), "Vector2f");
			m->add(constructor<sf::Vector2f(const sf::Vector2f&)>(), "Vector2f");
			m->add(fun([](sf::Vector2f& lhs, const sf::Vector2f& rhs) { return lhs = rhs; }), "=");
			m->add(fun([](sf::Vector2f& lhs, const sf::Vector2f& rhs) { return lhs + rhs; }), "+");
			m->add(fun([](sf::Vector2f& lhs, const sf::Vector2f& rhs) { return lhs - rhs; }), "-");
			m->add(fun([](sf::Vector2f& lhs, const sf::Vector2f& rhs) { return sf::Vector2f(lhs.x * rhs.x, lhs.y * rhs.y); }), "*");
			m->add(fun([](sf::Vector2f& lhs, const sf::Vector2f& rhs) { return sf::Vector2f(lhs.x / rhs.x, lhs.y / rhs.y); }), "/");
			m->add(fun([](sf::Vector2f& lhs, const float f) { return sf::Vector2f(lhs.x * f, lhs.y * f); }), "*");
			m->add(fun([](sf::Vector2f& lhs, const float f) { return sf::Vector2f(lhs.x / f, lhs.y / f); }), "/");
			m->add(fun([](const sf::Vector2f& lhs, const sf::Vector2f& rhs) { return lhs == rhs; }), "==");
			m->add(fun([](const sf::Vector2f& vec) { return "{ x: " + std::to_string(vec.x) + ", y: " + std::to_string(vec.y) + " }"; }), "to_string");

			// sf::Vector2i.
			m->add(user_type<sf::Vector2i>(), "Vector2i");
			m->add(fun(&sf::Vector2i::x), "x");
			m->add(fun(&sf::Vector2i::y), "y");
			m->add(constructor<sf::Vector2i()>(), "Vector2i");
			m->add(constructor<sf::Vector2i(int, int)>(), "Vector2i");
			m->add(constructor<sf::Vector2i(const sf::Vector2i&)>(), "Vector2i");
			m->add(fun([](sf::Vector2i& lhs, const sf::Vector2i& rhs) { return lhs = rhs; }), "=");
			m->add(fun([](sf::Vector2i& lhs, const sf::Vector2i& rhs) { return lhs + rhs; }), "+");
			m->add(fun([](sf::Vector2i& lhs, const sf::Vector2i& rhs) { return lhs - rhs; }), "-");
			m->add(fun([](const sf::Vector2i& lhs, const sf::Vector2i& rhs) { return lhs == rhs; }), "==");
			m->add(fun([](const sf::Vector2i& vec) { return "{ x: " + std::to_string(vec.x) + ", y: " + std::to_string(vec.y) + " }"; }), "to_string");

			// sf::String
			m->add(user_type<sf::String>(), "sf::String");
			m->add(constructor<sf::String()>(), "sf::String");
			m->add(type_conversion<sf::String, std::string>([](const sf::String& str) { return str.toAnsiString(); }));
			m->add(type_conversion<std::string, sf::String>([](const std::string& str) { return sf::String(str); }));
			m->add(fun([](const sf::String& str) { return str.toAnsiString(); }), "to_string");

			return m;
		}

		/**
		 * Register a ChaiScript module with sf::Window.
		 */
		ModulePtr addsfWindow(ModulePtr m = std::make_shared<Module>()) {

			// sf::Window
			m->add(user_type<sf::Window>(), "Window");
			m->add(constructor<sf::Window()>(), "Window");
			m->add(fun(&sf::Window::close), "close");
			m->add(fun(&sf::Window::isOpen), "isOpen");
			m->add(fun(&sf::Window::getPosition), "getPosition");
			m->add(fun(&sf::Window::setPosition), "setPosition");
			m->add(fun(&sf::Window::getSize), "getSize");
			m->add(fun(&sf::Window::setSize), "setSize");
			m->add(fun(&sf::Window::setTitle), "setTitle");
			m->add(fun(&sf::Window::setIcon), "setIcon");
			m->add(fun(&sf::Window::setVisible), "setVisible");
			m->add(fun(&sf::Window::setVerticalSyncEnabled), "setVerticalSyncEnabled");
			m->add(fun(&sf::Window::setMouseCursorVisible), "setMouseCursorVisible");
			m->add(fun(&sf::Window::setMouseCursorGrabbed), "setMouseCursorGrabbed");
			m->add(fun(&sf::Window::setKeyRepeatEnabled), "setKeyRepeatEnabled");
			m->add(fun(&sf::Window::setFramerateLimit), "setFramerateLimit");
			m->add(fun(&sf::Window::setJoystickThreshold), "setJoystickThreshold");
			m->add(fun(&sf::Window::setActive), "setActive");
			m->add(fun(&sf::Window::requestFocus), "requestFocus");
			m->add(fun(&sf::Window::hasFocus), "hasFocus");
			m->add(fun(&sf::Window::display), "display");


			// sf::Clipboard
			m->add(user_type<sf::Clipboard>(), "Clipboard");
			m->add(constructor<sf::Clipboard()>(), "Clipboard");
			m->add(fun([](const sf::Clipboard& clip)
			{
				return sf::Clipboard::getString();
			}), "getString");
			m->add(fun([](const sf::Clipboard& clip, const std::string& str)
			{
				return sf::Clipboard::setString(str);
			}), "setString");


			// sf::Mouse::Button
			m->add(type_conversion <sf::Mouse::Button, int > ());
			m->add_global_const(const_var(sf::Mouse::Button::Left), "MouseButtonLeft");
			m->add_global_const(const_var(sf::Mouse::Button::Right), "MouseButtonRight");
			m->add_global_const(const_var(sf::Mouse::Button::Middle), "MouseButtonMiddle");
			m->add_global_const(const_var(sf::Mouse::Button::XButton1), "MouseButtonXButton1");
			m->add_global_const(const_var(sf::Mouse::Button::XButton2), "MouseButtonXButton2");

			// sf::Mouse::Wheel
			m->add(type_conversion <sf::Mouse::Wheel, int >());
			m->add_global_const(const_var(sf::Mouse::Wheel::VerticalWheel), "MouseVerticalWheel");
			m->add_global_const(const_var(sf::Mouse::Wheel::HorizontalWheel), "MouseHorizontalWheel");

			// sf::Mouse
			m->add(user_type<sf::Mouse>(), "Mouse");
			m->add(constructor<sf::Mouse()>(), "Mouse");
			m->add(fun([](const sf::Mouse& mouse, const sf::Mouse::Button button)
			{
				return sf::Mouse::isButtonPressed(button);
			}), "isButtonPressed");
			m->add(fun([](const sf::Mouse& mouse)
			{
				return sf::Mouse::getPosition();
			}), "getPosition");

			m->add(fun([](const sf::Mouse& mouse, const sf::Vector2i& position)
			{
				return sf::Mouse::setPosition(position);
			}), "setPosition");
			m->add(fun([](const sf::Mouse& mouse, const sf::Window& relativeTo)
			{
				return sf::Mouse::getPosition(relativeTo);
			}), "getPosition");

			m->add(fun([](const sf::Mouse& mouse, const sf::Vector2i& position, const sf::Window& relativeTo)
			{
				return sf::Mouse::setPosition(position, relativeTo);
			}), "setPosition");

			return m;
		}

		/**
		 * Register a ChaiScript module with sf::Graphics.
		 */
		ModulePtr addsfGraphics(ModulePtr m = std::make_shared<Module>()) {

			// sf::IntRect
			m->add(user_type<sf::IntRect>(), "IntRect");
			m->add(fun(&sf::IntRect::top), "top");
			m->add(fun(&sf::IntRect::left), "left");
			m->add(fun(&sf::IntRect::width), "width");
			m->add(fun(&sf::IntRect::height), "height");
			m->add(constructor<sf::IntRect()>(), "IntRect");
			m->add(constructor<sf::IntRect(int, int, int, int)>(), "IntRect");
			m->add(constructor<sf::IntRect(const sf::Vector2i&, const sf::Vector2i&)>(), "IntRect");
			m->add(constructor<sf::IntRect(const sf::IntRect&)>(), "IntRect");
			m->add(fun([](const sf::IntRect* rect, int x, int y) {return rect->contains(x, y); }), "contains");
			m->add(fun([](const sf::IntRect* rect, const sf::Vector2i& vec) {return rect->contains(vec); }), "contains");
			m->add(fun([](const sf::IntRect* rect, const sf::IntRect& other) {return rect->intersects(other); }), "intersects");

			// sf::FloatRect
			m->add(user_type<sf::FloatRect>(), "FloatRect");
			m->add(fun(&sf::FloatRect::top), "top");
			m->add(fun(&sf::FloatRect::left), "left");
			m->add(fun(&sf::FloatRect::width), "width");
			m->add(fun(&sf::FloatRect::height), "height");
			m->add(constructor<sf::FloatRect()>(), "FloatRect");
			m->add(constructor<sf::FloatRect(float, float, float, float)>(), "FloatRect");
			m->add(constructor<sf::FloatRect(const sf::Vector2f&, const sf::Vector2f&)>(), "FloatRect");
			m->add(constructor<sf::FloatRect(const sf::FloatRect&)>(), "FloatRect");
			m->add(fun([](const sf::FloatRect* rect, float x, float y) {return rect->contains(x, y); }), "contains");
			m->add(fun([](const sf::FloatRect* rect, const sf::Vector2f& vec) {return rect->contains(vec); }), "contains");
			m->add(fun([](const sf::FloatRect* rect, const sf::FloatRect& other) {return rect->intersects(other); }), "intersects");

			// sf::Color
			m->add(user_type<sf::Color>(), "Color");
			m->add(fun(&sf::Color::r), "r");
			m->add(fun(&sf::Color::g), "g");
			m->add(fun(&sf::Color::b), "b");
			m->add(fun(&sf::Color::a), "a");
			m->add(constructor<sf::Color()>(), "Color");
			m->add(constructor<sf::Color(int, int, int, int)>(), "Color");
			m->add(constructor<sf::Color(int, int, int)>(), "Color");
			m->add(constructor<sf::Color(uint32)>(), "Color");
			m->add(constructor<sf::Color(const sf::Color&)>(), "Color");
			m->add(fun([](sf::Color& lhs, const sf::Color& rhs) { return lhs = rhs; }), "=");
			m->add(fun([](const sf::Color& lhs, const sf::Color& rhs) { return lhs == rhs; }), "==");
			m->add_global_const(const_var(sf::Color::Black), "Black");
			m->add_global_const(const_var(sf::Color::White), "White");
			m->add_global_const(const_var(sf::Color::Red), "Red");
			m->add_global_const(const_var(sf::Color::Green), "Green");
			m->add_global_const(const_var(sf::Color::Blue), "Blue");
			m->add_global_const(const_var(sf::Color::Yellow), "Yellow");
			m->add_global_const(const_var(sf::Color::Magenta), "Magenta");
			m->add_global_const(const_var(sf::Color::Cyan), "Cyan");
			m->add_global_const(const_var(sf::Color::Transparent), "Transparent");

			// sf::View
			m->add(user_type<sf::View>(), "View");
			m->add(constructor<sf::View(const sf::FloatRect&)>(), "View");
			m->add(constructor<sf::View(const sf::Vector2f&, const sf::Vector2f&) >(), "View");
			m->add(fun(static_cast<void(sf::View::*)(float, float)>(&sf::View::setCenter)), "setCenter");
			m->add(fun(static_cast<void(sf::View::*)(const sf::Vector2f&)>(&sf::View::setCenter)), "setCenter");
			m->add(fun(static_cast<void(sf::View::*)(float, float)>(&sf::View::setSize)), "setSize");
			m->add(fun(static_cast<void(sf::View::*)(const sf::Vector2f&)>(&sf::View::setSize)), "setSize");
			m->add(fun(&sf::View::setRotation), "setRotation");
			m->add(fun(&sf::View::setViewport), "setViewport");
			m->add(fun(&sf::View::setViewport), "getCenter");
			m->add(fun(&sf::View::setViewport), "getSize");
			m->add(fun(&sf::View::setViewport), "getRotation");
			m->add(fun(&sf::View::setViewport), "getViewport");
			m->add(fun(static_cast<void(sf::View::*)(float, float)>(&sf::View::move)), "move");
			m->add(fun(static_cast<void(sf::View::*)(const sf::Vector2f&)>(&sf::View::move)), "move");
			m->add(fun(&sf::View::rotate), "rotate");
			m->add(fun(&sf::View::zoom), "zoom");
			m->add(fun(&sf::View::getTransform), "getTransform");
			m->add(fun(&sf::View::getInverseTransform), "getInverseTransform");

			// sf::Drawable
			m->add(user_type<sf::Drawable>(), "Drawable");

			// sf::Transformable
			m->add(user_type<sf::Transformable>(), "Transformable");
			m->add(constructor<sf::Transformable()>(), "Transformable");			
			m->add(fun(static_cast<void( sf::Transformable::*)(float, float)>(&sf::Transformable::setPosition)), "setPosition");
			m->add(fun(static_cast<void( sf::Transformable::*)(const sf::Vector2f&)>(&sf::Transformable::setPosition)), "setPosition");
			m->add(fun(&sf::Transformable::setRotation), "setRotation");
			m->add(fun(static_cast<void(sf::Transformable::*)(float, float)>(&sf::Transformable::setScale)), "setScale");
			m->add(fun(static_cast<void(sf::Transformable::*)(const sf::Vector2f&)>(&sf::Transformable::setScale)), "setScale");
			m->add(fun(static_cast<void(sf::Transformable::*)(float, float)>(&sf::Transformable::setOrigin)), "setOrigin");
			m->add(fun(static_cast<void(sf::Transformable::*)(const sf::Vector2f&)>(&sf::Transformable::setOrigin)), "setOrigin");
			m->add(fun(&sf::Transformable::getPosition), "getPosition");
			m->add(fun(&sf::Transformable::getRotation), "getRotation");
			m->add(fun(&sf::Transformable::getScale), "getScale");
			m->add(fun(&sf::Transformable::getOrigin), "getOrigin");
			m->add(fun(static_cast<void(sf::Transformable::*)(float, float)>(&sf::Transformable::move)), "move");
			m->add(fun(static_cast<void(sf::Transformable::*)(const sf::Vector2f&)>(&sf::Transformable::move)), "move");
			m->add(fun(&sf::Transformable::rotate), "rotate");
			m->add(fun(static_cast<void(sf::Transformable::*)(float, float)>(&sf::Transformable::scale)), "scale");
			m->add(fun(static_cast<void(sf::Transformable::*)(const sf::Vector2f&)>(&sf::Transformable::scale)), "scale");
			m->add(fun(&sf::Transformable::getTransform), "getTransform");
			m->add(fun(&sf::Transformable::getInverseTransform), "getInverseTransform");

			// sf::Image
			m->add(user_type<sf::Image>(), "Image");
			m->add(constructor<sf::Image()>(), "Image");
			m->add(fun(static_cast<void(sf::Image::*)(unsigned width, unsigned height, const sf::Color& color)>(&sf::Image::create)), "create");
			m->add(fun(static_cast<void( sf::Image::*)(unsigned width, unsigned height, const sf::Uint8* pixels)>(&sf::Image::create)), "create");
			m->add(fun(&sf::Image::loadFromFile), "loadFromFile");
			m->add(fun(&sf::Image::loadFromMemory), "loadFromMemory");
			m->add(fun(&sf::Image::loadFromStream), "loadFromStream");
			m->add(fun(&sf::Image::saveToFile), "saveToFile");
			m->add(fun(&sf::Image::getSize), "getSize");
			m->add(fun(&sf::Image::createMaskFromColor), "createMaskFromColor");
			m->add(fun(&sf::Image::copy), "copy");
			m->add(fun(&sf::Image::setPixel), "setPixel");
			m->add(fun(&sf::Image::getPixel), "getPixel");
			m->add(fun(&sf::Image::getPixelsPtr), "getPixelsPtr");
			m->add(fun(&sf::Image::flipHorizontally), "flipHorizontally");
			m->add(fun(&sf::Image::flipVertically), "flipVertically");

			// sf::PrimitiveType
			m->add(type_conversion <sf::PrimitiveType, int >());
			m->add_global_const(const_var(sf::PrimitiveType::Points), "PrimitiveTypePoints");
			m->add_global_const(const_var(sf::PrimitiveType::Lines), "PrimitiveTypeLines");
			m->add_global_const(const_var(sf::PrimitiveType::LineStrip), "PrimitiveTypeLineStrip");
			m->add_global_const(const_var(sf::PrimitiveType::Triangles), "PrimitiveTypeTriangles");
			m->add_global_const(const_var(sf::PrimitiveType::TriangleStrip), "PrimitiveTypeTriangleStrip");
			m->add_global_const(const_var(sf::PrimitiveType::TriangleFan), "PrimitiveTypeTriangleFan");
			m->add_global_const(const_var(sf::PrimitiveType::Quads), "PrimitiveTypeQuads");

			// sf::Texture
			// sf::Texture::CoordinateType
			m->add(type_conversion <sf::Texture::CoordinateType, int >());
			m->add_global_const(const_var(sf::Texture::CoordinateType::Normalized), "CoordinateTypeNormalized");
			m->add_global_const(const_var(sf::Texture::CoordinateType::Pixels), "CoordinateTypePixels");
			//
			m->add(user_type<sf::Texture>(), "Texture");
			m->add(constructor<sf::Texture()>(), "Texture");
			m->add(constructor<sf::Texture(const sf::Texture&)>(), "Texture");
			m->add(fun(&sf::Texture::create), "create");
			m->add(fun(&sf::Texture::loadFromFile), "loadFromFile");
			m->add(fun(&sf::Texture::loadFromMemory), "loadFromMemory");
			m->add(fun(&sf::Texture::loadFromStream), "loadFromStream");
			m->add(fun(&sf::Texture::loadFromImage), "loadFromImage");
			m->add(fun(&sf::Texture::getSize), "getSize");
			m->add(fun(&sf::Texture::copyToImage), "copyToImage");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Uint8*)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Uint8*, unsigned, unsigned, unsigned, unsigned)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Texture&)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Texture&, unsigned, unsigned)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Image&)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Image&, unsigned, unsigned)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Window&)>(&sf::Texture::update)), "update");
			m->add(fun(static_cast<void(sf::Texture::*)(const sf::Window&, unsigned, unsigned)>(&sf::Texture::update)), "update");
			m->add(fun(&sf::Texture::setSmooth), "setSmooth");
			m->add(fun(&sf::Texture::isSmooth), "isSmooth");
			m->add(fun(&sf::Texture::setSrgb), "setSrgb");
			m->add(fun(&sf::Texture::isSrgb), "isSrgb");
			m->add(fun(&sf::Texture::setRepeated), "setRepeated");
			m->add(fun(&sf::Texture::isRepeated), "isRepeated");
			m->add(fun(&sf::Texture::generateMipmap), "generateMipmap");
			m->add(fun(&sf::Texture::swap), "swap");
			m->add(fun(&sf::Texture::bind), "bind");
			m->add(fun(&sf::Texture::getMaximumSize), "getMaximumSize");
			m->add(fun([](sf::Texture& left, const sf::Texture& right){
				return (left = right);
			}), "=");

			// sf:Shape
			m->add(user_type<sf::Shape>(), "Shape");
			m->add(chaiscript::base_class<sf::Drawable, sf::Shape>());
			m->add(chaiscript::base_class<sf::Transformable, sf::Shape>());
			m->add(fun(&sf::Shape::setTexture), "setTexture");
			m->add(fun(&sf::Shape::setTextureRect), "setTextureRect");
			m->add(fun(&sf::Shape::setFillColor), "setFillColor");
			m->add(fun(&sf::Shape::setOutlineColor), "setOutlineColor");
			m->add(fun(&sf::Shape::setOutlineThickness), "setOutlineThickness");
			m->add(fun(&sf::Shape::getTexture), "getTexture");
			m->add(fun(&sf::Shape::getTextureRect), "getTextureRect");
			m->add(fun(&sf::Shape::getFillColor), "getFillColor");
			m->add(fun(&sf::Shape::getOutlineColor), "getOutlineColor");
			m->add(fun(&sf::Shape::getOutlineThickness), "getOutlineThickness");
			m->add(fun(&sf::Shape::getPointCount), "getPointCount");
			m->add(fun(&sf::Shape::getPoint), "getPoint");
			m->add(fun(&sf::Shape::getLocalBounds), "getLocalBounds");
			m->add(fun(&sf::Shape::getGlobalBounds), "getGlobalBounds");

			// sf::CircleShape
			m->add(user_type<sf::CircleShape>(), "CircleShape");
			m->add(chaiscript::base_class<sf::Shape, sf::CircleShape>());
			m->add(base_class<sf::Drawable, sf::CircleShape>());
			m->add(base_class<sf::Transformable, sf::CircleShape>());
			m->add(constructor<sf::CircleShape()>(), "CircleShape");
			m->add(constructor<sf::CircleShape(float)>(), "CircleShape");
			m->add(constructor<sf::CircleShape(float, std::size_t)>(), "CircleShape");
			m->add(fun(&sf::CircleShape::setRadius), "setRadius");
			m->add(fun(&sf::CircleShape::getRadius), "getRadius");
			m->add(fun(&sf::CircleShape::setPointCount), "setPointCount");
			m->add(fun(&sf::CircleShape::getPointCount), "getPointCount");
			m->add(fun(&sf::CircleShape::getPoint), "getPoint");

			// sf::RectangleShape
			m->add(user_type<sf::RectangleShape>(), "RectangleShape");
			m->add(base_class<sf::Shape, sf::RectangleShape>());
			m->add(base_class<sf::Drawable, sf::RectangleShape>());
			m->add(base_class<sf::Transformable, sf::RectangleShape>());
			m->add(constructor<sf::RectangleShape()>(), "RectangleShape");
			m->add(constructor<sf::RectangleShape(const sf::Vector2f&)>(), "RectangleShape");
			m->add(fun(&sf::RectangleShape::setSize), "setSize");
			m->add(fun(&sf::RectangleShape::getSize), "getSize");
			m->add(fun(&sf::RectangleShape::getPointCount), "getPointCount");
			m->add(fun(&sf::RectangleShape::getPoint), "getPoint");

			// sf::ConvexShape
			m->add(user_type<sf::ConvexShape>(), "ConvexShape");
			m->add(chaiscript::base_class<sf::Shape, sf::ConvexShape>());
			m->add(base_class<sf::Drawable, sf::ConvexShape>());
			m->add(base_class<sf::Transformable, sf::ConvexShape>());
			m->add(constructor<sf::ConvexShape()>(), "ConvexShape");
			m->add(constructor<sf::ConvexShape(std::size_t)>(), "ConvexShape");
			m->add(fun(&sf::ConvexShape::setPointCount), "setPointCount");
			m->add(fun(&sf::ConvexShape::getPointCount), "getPointCount");
			m->add(fun(&sf::ConvexShape::getPointCount), "getPointCount");
			m->add(fun(&sf::ConvexShape::getPoint), "getPoint");

			// sf::Sprite
			m->add(user_type<sf::Sprite>(), "Sprite");
			m->add(chaiscript::base_class<sf::Drawable, sf::Sprite>());
			m->add(chaiscript::base_class<sf::Transformable, sf::Sprite>());
			m->add(constructor<sf::Sprite()>(), "Sprite");
			m->add(constructor<sf::Sprite(const sf::Texture&)>(), "Sprite");
			m->add(constructor<sf::Sprite(const sf::Texture&, const sf::IntRect&)>(), "Sprite");
			m->add(fun(&sf::Sprite::setTexture), "setTexture");
			m->add(fun(&sf::Sprite::setTextureRect), "setTextureRect");
			m->add(fun(&sf::Sprite::setColor), "setColor");
			m->add(fun(&sf::Sprite::getTexture), "getTexture");
			m->add(fun(&sf::Sprite::getTextureRect), "getTextureRect");
			m->add(fun(&sf::Sprite::getColor), "getColor");
			m->add(fun(&sf::Sprite::getLocalBounds), "getLocalBounds");
			m->add(fun(&sf::Sprite::getGlobalBounds), "getGlobalBounds");

			// sf::Vertex
			m->add(user_type<sf::Vertex>(), "Vertex");
			m->add(constructor<sf::Vertex()>(), "Vertex");
			m->add(constructor<sf::Vertex(const sf::Vector2f&)>(), "Vertex");
			m->add(constructor<sf::Vertex(const sf::Vector2f&, const sf::Color&)>(), "Vertex");
			m->add(constructor<sf::Vertex(const sf::Vector2f&, const sf::Vector2f&)>(), "Vertex");
			m->add(constructor<sf::Vertex(const sf::Vector2f&, const sf::Color&, const sf::Vector2f&)>(), "Vertex");
			m->add(fun(&sf::Vertex::position), "position");
			m->add(fun(&sf::Vertex::color), "color");
			m->add(fun(&sf::Vertex::texCoords), "texCoords");

			// sf::VertexArray
			m->add(user_type<sf::VertexArray>(), "VertexArray");
			m->add(chaiscript::base_class<sf::Drawable, sf::VertexArray>());
			m->add(constructor<sf::VertexArray()>(), "VertexArray");
			m->add(constructor<sf::VertexArray(sf::PrimitiveType, std::size_t)>(), "VertexArray");
			m->add(fun(&sf::VertexArray::getVertexCount), "getVertexCount");
			m->add(type_conversion<sf::VertexArray, std::vector<sf::Vertex>>([](const sf::VertexArray& varr)
			{
				std::vector<sf::Vertex> result;
				for (std::size_t i = 0; i < varr.getVertexCount(); ++i)
				{
					result.emplace_back(std::ref(varr[i]));
				}
				return result;
			}));
			m->add(fun([](sf::VertexArray& varr, std::size_t i)
			{
				return std::ref(varr[i]);
			}), "get");
			m->add(fun(&sf::VertexArray::clear), "clear");
			m->add(fun(&sf::VertexArray::resize), "resize");
			m->add(fun(&sf::VertexArray::append), "append");
			m->add(fun(&sf::VertexArray::setPrimitiveType), "setPrimitiveType");
			m->add(fun(&sf::VertexArray::getPrimitiveType), "getPrimitiveType");
			m->add(fun(&sf::VertexArray::getBounds), "getBounds");

			// sf::VertexBuffer
			// sf::VertexBuffer::Usage
			m->add(type_conversion <sf::VertexBuffer::Usage, int >());
			m->add_global_const(const_var(sf::VertexBuffer::Usage::Stream), "VertexBufferUsage_Stream");
			m->add_global_const(const_var(sf::VertexBuffer::Usage::Dynamic), "VertexBufferUsage_Dynamic");
			m->add_global_const(const_var(sf::VertexBuffer::Usage::Static), "VertexBufferUsage_Static");
			//
			m->add(user_type<sf::VertexBuffer>(), "VertexBuffer");
			m->add(chaiscript::base_class<sf::Drawable, sf::VertexBuffer>());
			m->add(constructor<sf::VertexBuffer()>(), "VertexBuffer");
			m->add(constructor<sf::VertexBuffer(sf::PrimitiveType)>(), "VertexBuffer");
			m->add(constructor<sf::VertexBuffer(sf::VertexBuffer::Usage)>(), "VertexBuffer");
			m->add(constructor<sf::VertexBuffer(sf::PrimitiveType, sf::VertexBuffer::Usage)>(), "VertexBuffer");
			m->add(constructor<sf::VertexBuffer(const sf::VertexBuffer&)>(), "VertexBuffer");
			m->add(fun(&sf::VertexBuffer::create), "create");
			m->add(fun(&sf::VertexBuffer::getVertexCount), "getVertexCount");
			m->add(fun(static_cast<bool( sf::VertexBuffer::*)(const sf::Vertex*)>(&sf::VertexBuffer::update)), "update");
			m->add(fun(static_cast<bool( sf::VertexBuffer::*)(const sf::Vertex*, unsigned, unsigned)>(&sf::VertexBuffer::update)), "update");
			m->add(fun(static_cast<bool( sf::VertexBuffer::*)(const sf::VertexBuffer&)>(&sf::VertexBuffer::update)), "update");
			m->add(fun([](sf::VertexBuffer& left,const sf::VertexBuffer& right)
			{
				return (left = right);
			}), "=");
			m->add(fun(&sf::VertexBuffer::swap), "swap");
			m->add(fun(&sf::VertexBuffer::setPrimitiveType), "setPrimitiveType");
			m->add(fun(&sf::VertexBuffer::getPrimitiveType), "getPrimitiveType");
			m->add(fun(&sf::VertexBuffer::setUsage), "setUsage");
			m->add(fun(&sf::VertexBuffer::getUsage), "getUsage");
			m->add(fun(&sf::VertexBuffer::bind), "bind");
			m->add(fun(&sf::VertexBuffer::isAvailable), "isAvailable");

			// sf::BlendMode
			// sf::BlendMode::Factor
			m->add(type_conversion <sf::BlendMode::Factor, int >());
			m->add_global_const(const_var(sf::BlendMode::Factor::Zero), "BlendModeFactor_Zero");
			m->add_global_const(const_var(sf::BlendMode::Factor::One), "BlendModeFactor_One");
			m->add_global_const(const_var(sf::BlendMode::Factor::SrcColor), "BlendModeFactor_SrcColor");
			m->add_global_const(const_var(sf::BlendMode::Factor::OneMinusSrcColor), "BlendModeFactor_OneMinusSrcColor");
			m->add_global_const(const_var(sf::BlendMode::Factor::DstColor), "BlendModeFactor_DstColor");
			m->add_global_const(const_var(sf::BlendMode::Factor::OneMinusDstColor), "BlendModeFactor_OneMinusDstColor");
			m->add_global_const(const_var(sf::BlendMode::Factor::SrcAlpha), "BlendModeFactor_SrcAlpha");
			m->add_global_const(const_var(sf::BlendMode::Factor::OneMinusSrcAlpha), "BlendModeFactor_OneMinusSrcAlpha");
			m->add_global_const(const_var(sf::BlendMode::Factor::DstAlpha), "BlendModeFactor_DstAlpha");
			m->add_global_const(const_var(sf::BlendMode::Factor::OneMinusDstAlpha), "BlendModeFactor_OneMinusDstAlpha");
			// sf::BlendMode::Equation
			m->add(type_conversion <sf::BlendMode::Equation, int >());
			m->add_global_const(const_var(sf::BlendMode::Equation::Add), "BlendModeEquation_Add");
			m->add_global_const(const_var(sf::BlendMode::Equation::Subtract), "BlendModeEquation_Subtract");
			m->add_global_const(const_var(sf::BlendMode::Equation::ReverseSubtract), "BlendModeEquation_ReverseSubtract");
			//
			m->add(user_type<sf::BlendMode>(), "BlendMode");
			m->add(constructor<sf::BlendMode()>(), "BlendMode");
			m->add(constructor<sf::BlendMode(sf::BlendMode::Factor, sf::BlendMode::Factor)>(), "BlendMode");
			m->add(constructor<sf::BlendMode(sf::BlendMode::Factor, sf::BlendMode::Factor, sf::BlendMode::Equation)>(), "BlendMode");
			m->add(constructor < sf::BlendMode(sf::BlendMode::Factor, sf::BlendMode::Factor,
				sf::BlendMode::Equation, sf::BlendMode::Factor,
				sf::BlendMode::Factor, sf::BlendMode::Equation) > (), "BlendMode");
			m->add(fun(&sf::BlendMode::colorSrcFactor), "colorSrcFactor");
			m->add(fun(&sf::BlendMode::colorDstFactor), "colorDstFactor");
			m->add(fun(&sf::BlendMode::colorEquation), "colorEquation");
			m->add(fun(&sf::BlendMode::alphaSrcFactor), "alphaSrcFactor");
			m->add(fun(&sf::BlendMode::alphaDstFactor), "alphaDstFactor");
			m->add(fun(&sf::BlendMode::alphaEquation), "alphaEquation");
			m->add(fun([](const sf::BlendMode& left, const sf::BlendMode& right)
			{
				return left == right;
			}), "==");

			// sf::Shader
			// sf::Shader::Type
			m->add(type_conversion <sf::Shader::Type, int >());
			m->add_global_const(const_var(sf::Shader::Type::Vertex), "ShaderType_Vertex");
			m->add_global_const(const_var(sf::Shader::Type::Geometry), "ShaderType_Geometry");
			m->add_global_const(const_var(sf::Shader::Type::Fragment), "ShaderType_Fragment");
			// sf::Shader::CurrentTextureType
			m->add(user_type<sf::Shader::CurrentTextureType>(), "Shader_CurrentTextureType");
			//
			m->add(user_type<sf::Shader>(), "Shader");
			m->add(constructor<sf::Shader()>(), "Shader");
			m->add(fun([](const sf::Shader& shader) { return sf::Shader::CurrentTexture; }), "CurrentTexture");
			m->add(fun(static_cast<bool(sf::Shader::*)(const std::basic_string<char>&, sf::Shader::Type)>(&sf::Shader::loadFromFile)), "loadFromFile");
			m->add(fun(static_cast<bool(sf::Shader::*)(const std::string&, const std::string&)>(&sf::Shader::loadFromFile)), "loadFromFile");
			m->add(fun(static_cast<bool(sf::Shader::*)(const std::string&, const std::string&, const std::string&)>(&sf::Shader::loadFromFile)), "loadFromFile");
			m->add(fun(static_cast<bool(sf::Shader::*)(const std::basic_string<char>&, sf::Shader::Type)>(&sf::Shader::loadFromMemory)), "loadFromMemory");
			m->add(fun(static_cast<bool(sf::Shader::*)(const std::string&, const std::string&)>(&sf::Shader::loadFromMemory)), "loadFromMemory");
			m->add(fun(static_cast<bool(sf::Shader::*)(const std::string&, const std::string&, const std::string&)>(&sf::Shader::loadFromMemory)), "loadFromMemory");
			m->add(fun(static_cast<bool(sf::Shader::*)(sf::InputStream&, sf::Shader::Type)>(&sf::Shader::loadFromStream)), "loadFromStream");
			m->add(fun(static_cast<bool(sf::Shader::*)(sf::InputStream&, sf::InputStream&)>(&sf::Shader::loadFromStream)), "loadFromStream");
			m->add(fun(static_cast<bool(sf::Shader::*)(sf::InputStream&, sf::InputStream&, sf::InputStream&)>(&sf::Shader::loadFromStream)), "loadFromStream");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, float)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Vec2&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Vec3&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Vec4&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, int)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Ivec2&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Ivec3&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Ivec4&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, bool)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Bvec2&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Bvec3&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Bvec4&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Mat3&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Mat4&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Texture&)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, sf::Shader::CurrentTextureType)>(&sf::Shader::setUniform)), "setUniform");
			m->add(fun([](sf::Shader& shader, const std::string& str)
			{
				shader.setUniform(str, sf::Shader::CurrentTexture);
			}), "setUniform");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Vec2*, std::size_t)>(&sf::Shader::setUniformArray)), "setUniformArray");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Vec3*, std::size_t)>(&sf::Shader::setUniformArray)), "setUniformArray");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Vec4*, std::size_t)>(&sf::Shader::setUniformArray)), "setUniformArray");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Mat3*, std::size_t)>(&sf::Shader::setUniformArray)), "setUniformArray");
			m->add(fun(static_cast<void(sf::Shader::*)(const std::string&, const sf::Glsl::Mat4*, std::size_t)>(&sf::Shader::setUniformArray)), "setUniformArray");
			m->add(fun(&sf::Shader::bind), "bind");
			m->add(fun(&sf::Shader::isAvailable), "isAvailable");
			m->add(fun(&sf::Shader::isGeometryAvailable), "isGeometryAvailable");

			// sf::RenderStates
			m->add(user_type<sf::RenderStates>(), "RenderStates");
			m->add(constructor<sf::RenderStates(const sf::BlendMode&)>(), "RenderStates");
			m->add(constructor<sf::RenderStates(const sf::Transform&)>(), "RenderStates");
			m->add(constructor<sf::RenderStates(const sf::Texture*)>(), "RenderStates");
			m->add(constructor<sf::RenderStates(const sf::Shader*)>(), "RenderStates");
			m->add(constructor<sf::RenderStates(const sf::BlendMode&, const sf::Transform&, const sf::Texture*, const sf::Shader*)>(), "RenderStates");
			m->add_global_const(const_var(sf::RenderStates::Default), "RenderStates_Default");
			m->add(fun([](const sf::RenderStates& states) {return sf::RenderStates::Default; }), "Default");
			m->add(fun(&sf::RenderStates::blendMode), "blendMode");
			m->add(fun(&sf::RenderStates::transform), "transform");
			m->add(fun(&sf::RenderStates::texture), "texture");
			m->add(fun(&sf::RenderStates::shader), "shader");

			// sf::RenderTarget
			m->add(user_type<sf::RenderTarget>(), "RenderTarget");
			m->add(fun(&sf::RenderTarget::clear), "clear");
			m->add(fun(&sf::RenderTarget::setView), "setView");
			m->add(fun(&sf::RenderTarget::getView), "getView");
			m->add(fun(&sf::RenderTarget::getDefaultView), "getDefaultView");
			m->add(fun(&sf::RenderTarget::getViewport), "getViewport");
			m->add(fun(static_cast<sf::Vector2f(sf::RenderTarget::*)(const sf::Vector2i&) const>(&sf::RenderTarget::mapPixelToCoords)), "mapPixelToCoords");
			m->add(fun(static_cast<sf::Vector2f(sf::RenderTarget::*)(const sf::Vector2i&, const sf::View&) const>(&sf::RenderTarget::mapPixelToCoords)), "mapPixelToCoords");
			m->add(fun(static_cast<sf::Vector2i(sf::RenderTarget::*)(const sf::Vector2f&) const>(&sf::RenderTarget::mapCoordsToPixel)), "mapCoordsToPixel");
			m->add(fun(static_cast<sf::Vector2i(sf::RenderTarget::*)(const sf::Vector2f&, const sf::View&) const>(&sf::RenderTarget::mapCoordsToPixel)), "mapCoordsToPixel");
			m->add(fun([](sf::RenderTarget& target, const sf::Drawable& drawable)
			{
				target.draw(drawable);
			}), "draw");
			m->add(fun(static_cast<void( sf::RenderTarget::*)(const sf::Drawable&, const sf::RenderStates&)>(&sf::RenderTarget::draw)), "draw");
			m->add(fun(static_cast<void( sf::RenderTarget::*)(const sf::Vertex*, std::size_t, sf::PrimitiveType, const sf::RenderStates&)>(&sf::RenderTarget::draw)), "draw");
			m->add(fun([](sf::RenderTarget& target, const sf::VertexBuffer& drawable)
			{
				target.draw(drawable);
			}), "draw");
			m->add(fun(static_cast<void( sf::RenderTarget::*)(const sf::VertexBuffer&, const sf::RenderStates&)>(&sf::RenderTarget::draw)), "draw");
			m->add(fun([](sf::RenderTarget& target, const sf::VertexBuffer& drawable, std::size_t firstVertex, std::size_t vertexCount)
			{
				target.draw(drawable, firstVertex, vertexCount);
			}), "draw");
			m->add(fun(static_cast<void(sf::RenderTarget::*)(const sf::VertexBuffer&, std::size_t, std::size_t, const sf::RenderStates&)>(&sf::RenderTarget::draw)), "draw");
			m->add(fun(&sf::RenderTarget::getSize), "getSize");
			m->add(fun(&sf::RenderTarget::setActive), "setActive");
			//m->add(fun(&sf::RenderTarget::pushGLStates), "pushGLStates");
			//m->add(fun(&sf::RenderTarget::popGLStates), "popGLStates");
			//m->add(fun(&sf::RenderTarget::resetGLStates), "resetGLStates");

			// sf::RenderTexture
			m->add(user_type<sf::RenderTexture>(), "RenderTexture");
			m->add(chaiscript::base_class<sf::RenderTarget, sf::RenderTexture>());
			m->add(constructor<sf::RenderTexture()>(), "RenderTexture");
			m->add(fun(static_cast<bool(sf::RenderTexture::*)(unsigned int, unsigned int, const sf::ContextSettings&)>(&sf::RenderTexture::create)), "create");
			m->add(fun([](sf::RenderTexture& texture, unsigned int width, unsigned int height)
			{
				return texture.create(width, height);
			}), "create");
			m->add(fun([](sf::RenderTexture& texture)
			{
				return sf::RenderTexture::getMaximumAntialiasingLevel();
			}), "getMaximumAntialiasingLevel");
			m->add(fun(&sf::RenderTexture::setSmooth), "setSmooth");
			m->add(fun(&sf::RenderTexture::isSmooth), "isSmooth");
			m->add(fun(&sf::RenderTexture::setRepeated), "setRepeated");
			m->add(fun(&sf::RenderTexture::isRepeated), "isRepeated");
			m->add(fun(&sf::RenderTexture::generateMipmap), "generateMipmap");
			m->add(fun(&sf::RenderTexture::setActive), "setActive");
			m->add(fun(&sf::RenderTexture::display), "display");
			m->add(fun(&sf::RenderTexture::getSize), "getSize");
			m->add(fun(&sf::RenderTexture::getTexture), "getTexture");

			// sf::RenderTexture
			m->add(user_type<sf::RenderWindow>(), "RenderWindow");
			m->add(chaiscript::base_class<sf::Window, sf::RenderWindow>());
			m->add(chaiscript::base_class<sf::RenderTarget, sf::RenderWindow>());
			m->add(constructor<sf::RenderWindow()>(), "RenderWindow");
			m->add(constructor<sf::RenderWindow(sf::VideoMode, const sf::String&, sf::Uint32, const sf::ContextSettings&)>(), "RenderWindow");
			m->add(constructor<sf::RenderWindow(sf::WindowHandle, const sf::ContextSettings&)>(), "RenderWindow");
			m->add(fun(&sf::RenderWindow::getSize), "getSize");
			m->add(fun(&sf::RenderWindow::setActive), "setActive");

			// sf::Glyph
			m->add(user_type<sf::Glyph>(), "Glyph");
			m->add(constructor<sf::Glyph()>(), "Glyph");
			m->add(fun(&sf::Glyph::advance), "advance");
			m->add(fun(&sf::Glyph::bounds), "bounds");
			m->add(fun(&sf::Glyph::textureRect), "textureRect");

			// sf::Font
			// sf::Font::Info
			m->add(user_type<sf::Font::Info>(), "FontInfo");
			m->add(constructor<sf::Font::Info()>(), "FontInfo");
			m->add(fun(&sf::Font::Info::family), "family");
			//
			m->add(user_type<sf::Font>(), "Font");			
			m->add(constructor<sf::Font()>(), "Font");
			m->add(constructor<sf::Font(const sf::Font&)>(), "Font");
			m->add(fun(&sf::Font::loadFromFile), "loadFromFile");
			m->add(fun(&sf::Font::loadFromMemory), "loadFromMemory");
			m->add(fun(&sf::Font::loadFromStream), "loadFromStream");
			m->add(fun(&sf::Font::getInfo), "getInfo");
			m->add(fun(&sf::Font::getGlyph), "getGlyph");
			m->add(fun(&sf::Font::getKerning), "getKerning");
			m->add(fun(&sf::Font::getLineSpacing), "getLineSpacing");
			m->add(fun(&sf::Font::getUnderlinePosition), "getUnderlinePosition");
			m->add(fun(&sf::Font::getUnderlineThickness), "getUnderlineThickness");
			m->add(fun(&sf::Font::getTexture), "getTexture");
			m->add(fun([](sf::Font& left, const sf::Font& right)
			{
				return (left = right);
			}), "=");

			// sf::Text
			// sf::Text::Style
			m->add(type_conversion <sf::Text::Style, int >());
			m->add_global_const(const_var(sf::Text::Style::Regular), "TextStyle_Regular");
			m->add_global_const(const_var(sf::Text::Style::Bold), "TextStyle_Bold");
			m->add_global_const(const_var(sf::Text::Style::Italic), "TextStyle_Italic");
			m->add_global_const(const_var(sf::Text::Style::Underlined), "TextStyle_Underlined");
			m->add_global_const(const_var(sf::Text::Style::StrikeThrough), "TextStyle_StrikeThrough");
			//
			m->add(user_type<sf::Text>(), "Text");
			m->add(chaiscript::base_class<sf::Drawable, sf::Text>());
			m->add(chaiscript::base_class<sf::Transformable, sf::Text>());
			m->add(constructor<sf::Text()>(), "Text");
			m->add(constructor<sf::Text(const sf::String&, const sf::Font&)>(), "Text");
			m->add(constructor<sf::Text(const sf::String&, const sf::Font&, unsigned int)>(), "Text");
			m->add(fun(&sf::Text::setString), "setString");
			m->add(fun(&sf::Text::setFont), "setFont");
			m->add(fun(&sf::Text::setCharacterSize), "setCharacterSize");
			m->add(fun(&sf::Text::setLineSpacing), "setLineSpacing");
			m->add(fun(&sf::Text::setLetterSpacing), "setLetterSpacing");
			m->add(fun(&sf::Text::setStyle), "setStyle");
			m->add(fun(&sf::Text::setFillColor), "setFillColor");
			m->add(fun(&sf::Text::setOutlineColor), "setOutlineColor");
			m->add(fun(&sf::Text::setOutlineThickness), "setOutlineThickness");
			m->add(fun(&sf::Text::getString), "getString");
			m->add(fun(&sf::Text::getFont), "getFont");
			m->add(fun(&sf::Text::getCharacterSize), "getCharacterSize");
			m->add(fun(&sf::Text::getLetterSpacing), "getLetterSpacing");
			m->add(fun(&sf::Text::getLineSpacing), "getLineSpacing");
			m->add(fun(&sf::Text::getStyle), "getStyle");
			m->add(fun(&sf::Text::getFillColor), "getFillColor");
			m->add(fun(&sf::Text::getOutlineColor), "getOutlineColor");
			m->add(fun(&sf::Text::getOutlineThickness), "getOutlineThickness");
			m->add(fun(&sf::Text::findCharacterPos), "findCharacterPos");
			m->add(fun(&sf::Text::getLocalBounds), "getLocalBounds");
			m->add(fun(&sf::Text::getGlobalBounds), "getGlobalBounds");

			return m;
		}

	  /**
	   * Bootstrap a ChaiScript module with SFML support.
	   */
	  ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
	  {
		  addsfSystem(m);
		  addsfWindow(m);
		  addsfGraphics(m);

		return m;
	  }
	}
  }
}
