using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using AForge;
using AForge.Video;
using AForge.Video.DirectShow;

namespace TestVideo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        FilterInfoCollection videoDevices;
        VideoCaptureDevice videoSource;
        private void button1_Click(object sender, EventArgs e)
        {
            // enumerate video devices
            videoDevices = new FilterInfoCollection(
                     FilterCategory.VideoInputDevice);
            // create video source
            videoSource = new VideoCaptureDevice(
                    videoDevices[0].MonikerString);
            // set NewFrame event handler
            videoSource.NewFrame += new NewFrameEventHandler(video_NewFrame);
            // start the video source
            videoSource.Start();
            // ...
            // signal to stop
            //videoSource.SignalToStop();
            // ...


        }
        private void video_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            // get new frame

            pictureBox1.Image = (Bitmap)eventArgs.Frame.Clone();
            // process the frame
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            videoSource.SignalToStop();
        }
    }
}
