Public Class OptionsForm

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Me.Close()
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        If My.Computer.FileSystem.DirectoryExists(TextBox1.Text) Then
            Options.Directory = TextBox1.Text
            Options.SongGap = NumericUpDown1.Value
            Dim hold As Long = DateTimePicker1.Value.Ticks - DateTimePicker1.MinDate.Ticks
            Options.PlaylistLength = New TimeSpan(hold).TotalSeconds
            Me.Close()
        Else
            MessageBox.Show("Error, invalid path specified", "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If (FolderBrowserDialog1.ShowDialog = Windows.Forms.DialogResult.OK) Then
            TextBox1.Text = FolderBrowserDialog1.SelectedPath
        End If
    End Sub

    Private Sub OptionsForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        TextBox1.Text = My.Computer.FileSystem.SpecialDirectories.MyMusic.ToString()
    End Sub
End Class