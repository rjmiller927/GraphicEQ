/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Filter.hpp"


//==============================================================================
/**
*/
class GraphicEqAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Slider::Listener,
                                       public Timer
{
public:
    GraphicEqAudioProcessorEditor (GraphicEqAudioProcessor&);
    ~GraphicEqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    //Override the internal sliderValueChanged method JUCE contains. Need to do something similar for ALL methods added and used in the plugin
    void sliderValueChanged(Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GraphicEqAudioProcessor& processor;
    
    //Define the slider objects to be used on the GUI
    Slider LSFgainSlider;
    Label lsfLabel;
    Slider PKF1gainSlider;
    Label pkf1Label;
    Slider PKF2gainSlider;
    Label pkf2Label;
    Slider PKF3gainSlider;
    Label pkf3Label;
    Slider PKF4gainSlider;
    Label pkf4Label;
    Slider PKF5gainSlider;
    Label pkf5Label;
    Slider PKF6gainSlider;
    Label pkf6Label;
    Slider HSFgainSlider;
    Label hsfLabel;
    
    //==============================================================================
    // GUI componenet attachements
    //==============================================================================
    std::vector<std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment>> sliderAttachment;
    
    //Conditional variables for smoothing. Set the LinearSmoothedValue getNextValue() to these variables and use them in a conditional statement if getNextValue() is outside of our range, then set these variables to the max/min
    float lowShelfGain = 0.0;
    float peakOneGain = 0.0;
    float peakTwoGain = 0.0;
    float peakThreeGain = 0.0;
    float peakFourGain = 0.0;
    float peakFiveGain = 0.0;
    float peakSixGain = 0.0;
    float highShelfGain = 0.0;
    
    //Override Timer Callbak method
    void timerCallback() override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicEqAudioProcessorEditor)
};
