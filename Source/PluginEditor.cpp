/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Filter.hpp"


//==============================================================================
GraphicEqAudioProcessorEditor::GraphicEqAudioProcessorEditor (GraphicEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (675, 500);
    
    //==========================================================================
    //Various settings for our slider objects. 'this' refers to the plugin editor class
    
    //Low Shelf Filter Slider and Text Label
    //LSFgainSlider.addListener(this);
    LSFgainSlider.setSliderStyle(Slider::LinearVertical);
    LSFgainSlider.setBounds(75, 83.333, 50, 333.333);
    LSFgainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    LSFgainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(LSFgainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "LSFgain", LSFgainSlider));
    
    lsfLabel.setText("125Hz", dontSendNotification);
    lsfLabel.attachToComponent(&LSFgainSlider, false);
    addAndMakeVisible(lsfLabel);
    
    //Peaking Filter 1 Slider
    //PKF1gainSlider.addListener(this);
    PKF1gainSlider.setSliderStyle(Slider::LinearVertical);
    PKF1gainSlider.setBounds(150, 83.333, 50, 333.333);
    PKF1gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    PKF1gainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(PKF1gainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "250gain", PKF1gainSlider));
    
    pkf1Label.setText("250Hz", dontSendNotification);
    pkf1Label.attachToComponent(&PKF1gainSlider, false);
    addAndMakeVisible(pkf1Label);
    
    //Peaking Filter 2 Slider
    //PKF2gainSlider.addListener(this);
    PKF2gainSlider.setSliderStyle(Slider::LinearVertical);
    PKF2gainSlider.setBounds(225, 83.333, 50, 333.333);
    PKF2gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    PKF2gainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(PKF2gainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "500gain", PKF2gainSlider));
    
    pkf2Label.setText("500Hz", dontSendNotification);
    pkf2Label.attachToComponent(&PKF2gainSlider, false);
    addAndMakeVisible(pkf2Label);
    
    //Peaking Filter 3 Slider
    //PKF3gainSlider.addListener(this);
    PKF3gainSlider.setSliderStyle(Slider::LinearVertical);
    PKF3gainSlider.setBounds(300, 83.333, 50, 333.333);
    PKF3gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    PKF3gainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(PKF3gainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "1kgain", PKF3gainSlider));
    
    pkf3Label.setText("1kHz", dontSendNotification);
    pkf3Label.attachToComponent(&PKF3gainSlider, false);
    addAndMakeVisible(pkf3Label);
    
    //Peaking Filter 4 Slider
    //PKF4gainSlider.addListener(this);
    PKF4gainSlider.setSliderStyle(Slider::LinearVertical);
    PKF4gainSlider.setBounds(375, 83.333, 50, 333.333);
    PKF4gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    PKF4gainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(PKF4gainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "2kgain", PKF4gainSlider));
    
    pkf4Label.setText("2kHz", dontSendNotification);
    pkf4Label.attachToComponent(&PKF4gainSlider, false);
    addAndMakeVisible(pkf4Label);
    
    //Peaking Filter 5 Slider
    //PKF5gainSlider.addListener(this);
    PKF5gainSlider.setSliderStyle(Slider::LinearVertical);
    PKF5gainSlider.setBounds(450, 83.333, 50, 333.333);
    PKF5gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    PKF5gainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(PKF5gainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "4kgain", PKF5gainSlider));
    
    pkf5Label.setText("4kHz", dontSendNotification);
    pkf5Label.attachToComponent(&PKF5gainSlider, false);
    addAndMakeVisible(pkf5Label);
    
    //Peaking Filter 6 Slider
    //PKF6gainSlider.addListener(this);
    PKF6gainSlider.setSliderStyle(Slider::LinearVertical);
    PKF6gainSlider.setBounds(525, 83.333, 50, 333.333);
    PKF6gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    PKF6gainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(PKF6gainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "8kgain", PKF6gainSlider));
    
    pkf6Label.setText("8kHz", dontSendNotification);
    pkf6Label.attachToComponent(&PKF6gainSlider, false);
    addAndMakeVisible(pkf6Label);
    
    //High Shelf Filter Slider
    //HSFgainSlider.addListener(this);
    HSFgainSlider.setSliderStyle(Slider::LinearVertical);
    HSFgainSlider.setBounds(600, 83.333, 50, 333.333);
    HSFgainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    HSFgainSlider.setRange(-24.0, 12.0, 0.1);
    addAndMakeVisible(HSFgainSlider);
    
    sliderAttachment.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "HSFgain", HSFgainSlider));
    
    hsfLabel.setText("12kHz", dontSendNotification);
    hsfLabel.attachToComponent(&HSFgainSlider, false);
    addAndMakeVisible(hsfLabel);
    
    startTimer(20);
}

GraphicEqAudioProcessorEditor::~GraphicEqAudioProcessorEditor()
{
}

//==============================================================================
void GraphicEqAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::darkslateblue);
    g.setColour (Colours::oldlace);
    
    //Title of plugin in the upper left corner
    g.setFont(25.0f);
    g.drawFittedText("Graphic Equalizer", 0, 0, 250, 50, Justification::left, 1);
    g.setFont(10.0f);
    g.drawFittedText("Ryan Miller", 0, 15, 150, 50, Justification::centred, 1);
    
}

void GraphicEqAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

//This method applies the position of the slider to value of the gain for each filter in the process block
void GraphicEqAudioProcessorEditor::sliderValueChanged(Slider *slider){
    
    /*
    //LPF
    if (slider == &LSFgainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.lowShelfSmooth->setValue(slider -> getValue(), false);
    }
    
    //PKF1
    if (slider == &PKF1gainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.peakOneSmooth->setValue(slider -> getValue(), false);
    }
    
    //PKF2
    if (slider == &PKF2gainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.peakTwoSmooth->setValue(slider -> getValue(), false);
    }
    
    //PKF3
    if (slider == &PKF3gainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.peakThreeSmooth->setValue(slider -> getValue(), false);
    }
    
    //PKF4
    if (slider == &PKF4gainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.peakFourSmooth->setValue(slider -> getValue(), false);
    }
    
    //PKF5
    if (slider == &PKF5gainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.peakFiveSmooth->setValue(slider -> getValue(), false);
    }
    
    //PKF6
    if (slider == &PKF6gainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.peakSixSmooth->setValue(slider -> getValue(), false);
    }
    
    //HSF
    if (slider == &HSFgainSlider){
        //Set the target value for the smoothing object to the slider value selected by the user
        processor.highShelfSmooth->setValue(slider -> getValue(), false);
    }
     */
}

void GraphicEqAudioProcessorEditor::timerCallback(){
    
    //Whenever this method is called, it sets the value of the fader on the GUI to the value of the associated gain variable, so that there is a link between the GUI fader and the automation parameter
    
    /*
    LSFgainSlider.setValue(*processor.LSFgain, dontSendNotification);
    PKF1gainSlider.setValue(*processor.PKF1gain, dontSendNotification);
    PKF2gainSlider.setValue(*processor.PKF2gain, dontSendNotification);
    PKF3gainSlider.setValue(*processor.PKF3gain, dontSendNotification);
    PKF4gainSlider.setValue(*processor.PKF4gain, dontSendNotification);
    PKF5gainSlider.setValue(*processor.PKF5gain, dontSendNotification);
    PKF6gainSlider.setValue(*processor.PKF6gain, dontSendNotification);
    HSFgainSlider.setValue(*processor.HSFgain, dontSendNotification);
     */
    
    
}


